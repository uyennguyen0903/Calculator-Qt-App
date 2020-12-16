#include "Controller.h"

void Controller::SetOperator(Operator* op) {
  delete operator_;
  operator_ = op;
}

int Controller::ParseProgram(const QStringList& list, int position) {
  QString prog_str = "[";
  int cnt = 1;
  ++position;  // Skip the first '['.

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
    operator_->Execute();
  }

  if (op == "STO") {
    SetOperator(new STO(literal_manager_, pile_));
    operator_->Execute();
  }

  if (op == "EVAL") {
    EvalExpressionOrProgram();
  }
}

void Controller::EvalExpressionOrProgram() {
  Literal& exp_or_prog = pile_.Top();
  Literal::LiteralType type = exp_or_prog.GetLiteralType();

  QString str = exp_or_prog.Print();

  if (type == Literal::LiteralType::kExpression) {
    Literal* atom_value = atom_manager_.GetAtom(str).CopyAtomValue();
    if (atom_value != nullptr) {
      pile_.Pop();
      if (atom_value->GetLiteralType() == Literal::LiteralType::kProgram) {
        str = atom_value->Print();
        Commande(str.mid(1, str.length() - 2));
      } else {
        pile_.Push(*atom_value);
      }
    } else {
      throw(ComputerException("Expression n'est associée à aucune valeur."));
    }
  } else if (type = Literal::LiteralType::kProgram) {
    // Effacer "]" & "[".
    pile_.Pop();
    Commande(str.mid(1, str.length() - 2));
  } else {
    throw(ComputerException(
        "Commande invalide. EVAL opération est seulement pour "
        "expression/programme litérale."));
  }
}

void Controller::Commande(const QString& expression) {
  QStringList operand_list =
      expression.split(QRegExp("\\s+"), QString::SkipEmptyParts);

  for (int i = 0; i < operand_list.size(); ++i) {
    try {
      const QString cur_operand = operand_list.at(i);

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
          // continue;
        }

        if (type == Operand::OperandType::kInteger) {
          pile_.Push(
              literal_manager_.AddLiteral(new Integer(cur_operand.toInt())));
          // continue;
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
              QString prog_str = atom_value->Print();
              // Effacer "]" & "[".
              Commande(prog_str.mid(1, prog_str.length() - 2));
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
      for (int j = i; j < operand_list.size(); ++j) {
        command_error_.append(operand_list.at(j));
        if (j != operand_list.size() - 1) command_error_.append(" ");
      }
      throw(ComputerException(pile_.GetMessage()));
    }
  }
}