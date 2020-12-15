#include "Controller.h"

void Controller::SetOperator(Operator* op) {
  delete operator_;
  operator_ = op;
}

int Controller::ParseProgram(const QStringList& list, int position) {
  QString prog_str = "";
  int cnt = 0;

  do {
    const QString cur_operand = list.at(position++);
    if (cur_operand == "[") {
      ++cnt;
    } else if (cur_operand == "]") {
      if (cnt > 0) {
        --cnt;
      } else {
        throw(ComputerException("Programme invalid."));
      }
    } else if (FindTypeOperand(cur_operand) ==
               Operand::OperandType::kUndefined) {
      throw(ComputerException("Programme contient operand inconnu."));
    }
    prog_str.append(" " + cur_operand);
  } while (cnt != 0 && position < list.size());

  if (cnt != 0) {
    throw(ComputerException("Programme invalid."));
  }

  pile_.Push(literal_manager_.AddLiteral(new Program(prog_str)));

  return position;
}

void Controller::ExecuteOperator(const QString& op) {
  if (op == "+") {
    SetOperator(new AdditionOperator(literal_manager_, pile_));
  }
  if (op == "STO") {
    SetOperator(new STO(literal_manager_, pile_));
  }
  operator_->Execute();
}

QString Controller::Commande(const QString& expression) {
  QStringList operand_list =
      expression.split(QRegExp("\\s+"), QString::SkipEmptyParts);

  int error_position = -1;

  for (int i = 0; i < operand_list.size(); ++i) {
    try {
      const QString cur_operand = operand_list.at(i);
      error_position = i;

      if (cur_operand == "[") {
        int next_position = ParseProgram(operand_list, i);
        i = next_position - 1;
      } else {
        Operand::OperandType type = FindTypeOperand(cur_operand);

        if (type == Operand::OperandType::kUndefined) {
          throw(ComputerException("Operand inconnu."));
        }

        if (type == Operand::OperandType::kOperator) {
          ExecuteOperator(cur_operand);
        }

        if (type == Operand::OperandType::kInteger) {
          pile_.Push(
              literal_manager_.AddLiteral(new Integer(cur_operand.toInt())));
        }

        if (type == Operand::OperandType::kReal) {
          pile_.Push(
              literal_manager_.AddLiteral(new Real(cur_operand.toDouble())));
        }

        if (type == Operand::OperandType::kFraction) {
          QStringList list = cur_operand.split("/", QString::SkipEmptyParts);
          pile_.Push(literal_manager_.AddLiteral(
              new Fraction(list.at(0).toInt(), list.at(1).toInt())));
        }

        if (type == Operand::OperandType::kAtom) {
          if (!atom_manager_.CheckExistedAtom(cur_operand)) {
            atom_manager_.AddAtom(cur_operand, nullptr);
          }
          Literal* atom_value = atom_manager_.EvalAtom(cur_operand);
          if (atom_value == nullptr) {
            pile_.SetMessage(
                cur_operand +
                " n'a aucune valeur associée. Créé un expression litéral");
            pile_.Push(literal_manager_.AddLiteral(new ExpressionLiteral(
                cur_operand, atom_manager_.GetAtom(cur_operand))));
          } else {
            if (atom_value->GetLiteralType() ==
                Literal::LiteralType::kProgram) {
              Commande(atom_value->Print());
            } else {
              pile_.Push(literal_manager_.AddLiteral(atom_value));
            }
          }
        }

        if (type == Operand::OperandType::kExpression) {
          const QString id = cur_operand.mid(1, cur_operand.length() - 2);
          if (!atom_manager_.CheckExistedAtom(id)) {
            atom_manager_.AddAtom(id, nullptr);
          }
          pile_.Push(literal_manager_.AddLiteral(
              new ExpressionLiteral(id, atom_manager_.GetAtom(id))));
        }
      }
    } catch (ComputerException& error) {
      pile_.SetMessage(error.GetInfo());
      error_position = i;
      break;
    }

    if (i == operand_list.size() - 1) error_position = -1;
  }

  if (error_position == -1) return "";

  QString str_rest = "";
  for (int i = error_position; i < operand_list.size(); ++i) {
    str_rest.append(operand_list.at(i));
    if (i != operand_list.size() - 1) str_rest.append(" ");
  }
  return str_rest;
}