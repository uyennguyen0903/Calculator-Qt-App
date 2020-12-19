#include "Utils.h"

bool ValidIdentifier(const QString& str) {
  if (!str[0].isLetter()) return false;

  if (Operator::kOperatorList.find(str) != Operator::kOperatorList.end())
    return false;

  for (int i = 0; i < str.length(); ++i) {
    if (str[i].isDigit() || (str[i].isUpper() && str[i].isLetter()))
      continue;
    else
      return false;
  }
  return true;
}

Operand::OperandType FindTypeOperand(const QString& str) {
  if (Operator::kOperatorList.find(str) != Operator::kOperatorList.end()) {
    return Operand::OperandType::kOperator;
  }

  bool ValidType;

  if (str.indexOf("-") == 0)
    throw(ComputerException("Impossible de saisir un nombre négatif."));

  if (str.indexOf("+") == 0) throw(ComputerException("Invalid command."));

  str.toLong(&ValidType);
  if (ValidType) {
    return Operand::OperandType::kInteger;
  }

  str.toFloat(&ValidType);
  if (ValidType) {
    return Operand::OperandType::kReal;
  }

  if (str.indexOf("/") != -1) {
    QStringList list = str.split("/", QString::SkipEmptyParts);
    if (list.size() != 2) return Operand::OperandType::kUndefined;

    list.at(0).toLong(&ValidType);
    if (!ValidType) return Operand::OperandType::kUndefined;

    list.at(1).toLong(&ValidType);
    if (!ValidType) return Operand::OperandType::kUndefined;

    return Operand::OperandType::kFraction;
  }

  if (str.length() > 2 && str.at(0) == "'" && str.at(str.length() - 1) == "'") {
    if (ValidIdentifier(str.mid(1, str.length() - 2))) {
      return Operand::OperandType::kExpression;
    } else {
      throw(ComputerException("Invalid expression"));
    }
  }
  if (ValidIdentifier(str)) {
    return Operand::OperandType::kAtom;
  } else {
    throw(ComputerException("Invalid expression"));
  }

  return Operand::OperandType::kUndefined;
}

Fraction* ConvertIntToFraction(Literal& num) {
  Integer& n = dynamic_cast<Integer&>(num);
  return new Fraction(n.GetInt(), 1);
}

Real* ConvertIntToReal(Literal& num) {
  Integer& n = dynamic_cast<Integer&>(num);
  return new Real(float(n.GetInt()));
}

Real* ConvertFractionToReal(Literal& frac) {
  Fraction& n = dynamic_cast<Fraction&>(frac);
  return new Real(float(n.GetNumerator()) / float(n.GetDenominator()));
}

Real* ConvertToReal(Literal& num) {
  if (num.GetLiteralType() == Literal::LiteralType::kInteger) {
    return ConvertIntToReal(num);
  } else {
    return ConvertFractionToReal(num);
  }
}

bool LogicTest(Literal* const literal) {
  if (literal == nullptr) return true;
  if (literal->GetLiteralType() == Literal::LiteralType::kExpression) {
    ExpressionLiteral* exp = dynamic_cast<ExpressionLiteral*>(literal);
    return LogicTest(exp->GetAtom().CopyAtomValue());
  }
  if (literal->GetLiteralType() == Literal::LiteralType::kInteger) {
    Integer* n = dynamic_cast<Integer*>(literal);
    if (n->GetInt() == 0) return false;
  }
  return true;
}
