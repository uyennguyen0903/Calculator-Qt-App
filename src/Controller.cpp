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
        throw(ComputerException("Programme invalide."));
      }
    } else if (FindTypeOperand(cur_operand) ==
               Operand::OperandType::kUndefined) {
      throw(ComputerException("Programme contient operand inconnu."));
    }
    prog_str.append(" " + cur_operand);
  } while (cnt != 0 && position < list.size());

  if (cnt != 0) {
    throw(ComputerException("Programme invalide."));
  }

  pile_.Push(literal_manager_.AddLiteral(new Program(prog_str)));

  return position;
}

void Controller::CommandeProcess(const QString& command) {
  QStringList operand_list =
      command.split(QRegExp("\\s+"), QString::SkipEmptyParts);

  for (int i = 0; i < operand_list.size(); ++i) {
    try {
      const QString cur_operand = operand_list.at(i);

      if (cur_operand == "[") {
        i = ParseProgram(operand_list, i) - 1;
        continue;
      }

      Operand::OperandType type = FindTypeOperand(cur_operand);

      if (type == Operand::OperandType::kUndefined) {
        throw(ComputerException("Operand inconnu."));
      }

      if (type == Operand::OperandType::kOperator) {
        ExecuteOperator(cur_operand);
        continue;
      }

      if (type == Operand::OperandType::kInteger) {
        pile_.Push(
            literal_manager_.AddLiteral(new Integer(cur_operand.toLong())));
        continue;
      }

      if (type == Operand::OperandType::kReal) {
        if (trunc(cur_operand.toFloat()) == cur_operand.toFloat()) {
          pile_.Push(literal_manager_.AddLiteral(
              new Integer(trunc(cur_operand.toFloat()))));
        } else {
          pile_.Push(
              literal_manager_.AddLiteral(new Real(cur_operand.toFloat())));
        }
        continue;
      }

      if (type == Operand::OperandType::kFraction) {
        QStringList list = cur_operand.split("/", QString::SkipEmptyParts);
        long n = list.at(0).toInt();
        long d = list.at(1).toInt();
        if (d == 0) {
          throw(ComputerException("Dénominateur doit être non null."));
        }
        if (n == 0) {
          pile_.Push(literal_manager_.AddLiteral(new Integer(long(0))));
        } else {
          long gcd = __gcd(n, d);
          n /= gcd;
          d /= gcd;
          if (d != 1) {
            pile_.Push(literal_manager_.AddLiteral(new Fraction(n, d)));
          } else {
            pile_.Push(literal_manager_.AddLiteral(new Integer(n)));
          }
        }
        continue;
      }

      if (type == Operand::OperandType::kExpression) {
        const QString id = cur_operand.mid(1, cur_operand.length() - 2);

        if (!atom_manager_.CheckExistedAtom(id)) {
          atom_manager_.AddAtom(id, nullptr);
        }

        pile_.Push(literal_manager_.AddLiteral(
            new ExpressionLiteral(id, atom_manager_.GetAtom(id))));
        continue;
      }

      if (type == Operand::OperandType::kAtom) {
        if (!atom_manager_.CheckExistedAtom(cur_operand)) {
          throw(ComputerException("Atome n'est pas initialisée"));
          pile_.Push(literal_manager_.AddLiteral(new ExpressionLiteral(
              cur_operand, atom_manager_.GetAtom(cur_operand))));
          continue;
        }

        Literal* atom_value = atom_manager_.EvalAtom(cur_operand);

        if (atom_value->GetLiteralType() == Literal::LiteralType::kProgram) {
          QString prog_str = atom_value->Print();
          // Effacer "]" & "[".
          CommandeProcess(prog_str.mid(1, prog_str.length() - 2));
        } else {
          pile_.Push(literal_manager_.AddLiteral(atom_value));
        }
      }
    } catch (ComputerException& error) {
      pile_.SetMessage(error.GetInfo());
      throw(ComputerException(pile_.GetMessage()));
    }
  }
}

void Controller::ExecuteOperator(const QString& op) {
  if (op == "+") {
    SetOperator(new AdditionOperator(literal_manager_, pile_));
    operator_->Execute();
  }

  if (op == "-") {
    SetOperator(new SubtractionOperator(literal_manager_, pile_));
    operator_->Execute();
  }

  if (op == "*") {
    SetOperator(new MultiplyOperator(literal_manager_, pile_));
    operator_->Execute();
  }

  if (op == "/") {
    SetOperator(new DivisionOperator(literal_manager_, pile_));
    operator_->Execute();
  }

  if (op == "DIV") {
    SetOperator(new DivMod(literal_manager_, pile_, true));
    operator_->Execute();
  }

  if (op == "MOD") {
    SetOperator(new DivMod(literal_manager_, pile_, false));
    operator_->Execute();
  }

  if (op == ">") {
    SetOperator(new Greater(literal_manager_, pile_, false, false));
    operator_->Execute();
  }

  if (op == ">=") {
    SetOperator(new Greater(literal_manager_, pile_, false, true));
    operator_->Execute();
  }

  if (op == "<") {
    SetOperator(new Greater(literal_manager_, pile_, true, false));
    operator_->Execute();
  }

  if (op == "<=") {
    SetOperator(new Greater(literal_manager_, pile_, true, true));
    operator_->Execute();
  }

  if (op == "=") {
    SetOperator(new Equal(literal_manager_, pile_, false));
    operator_->Execute();
  }

  if (op == "!=") {
    SetOperator(new Equal(literal_manager_, pile_, true));
    operator_->Execute();
  }

  if (op == "AND") {
    SetOperator(new AndOr(literal_manager_, pile_, true));
    operator_->Execute();
  }

  if (op == "OR") {
    SetOperator(new AndOr(literal_manager_, pile_, false));
    operator_->Execute();
  }

  if (op == "NOT") {
    SetOperator(new Not(literal_manager_, pile_));
    operator_->Execute();
  }

  if (op == "STO") {
    SetOperator(new STO(literal_manager_, pile_));
    operator_->Execute();
  }

  if (op == "NEG") {
    SetOperator(new NegativeOperator(literal_manager_, pile_));
    operator_->Execute();
  }

  if (op == "NUM") {
    SetOperator(new NumDen(literal_manager_, pile_, true));
    operator_->Execute();
  }

  if (op == "DEN") {
    SetOperator(new NumDen(literal_manager_, pile_, false));
    operator_->Execute();
  }

  if (op == "EVAL") {
    EVAL();
  }

  if (op == "DUP") {
    DUP();
  }

  if (op == "DROP") {
    DROP();
  }

  if (op == "SWAP") {
    SWAP();
  }

  if (op == "CLEAR") {
    CLEAR();
  }

  if (op == "FORGET") {
    FORGET();
  }

  if (op == "IFT") {
    IFT();
  }

  if (op == "IFTE") {
    IFTE();
  }
}
