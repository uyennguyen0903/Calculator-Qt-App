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

  int int_nb = str.toInt(&ValidType);
  if (ValidType) {
    return Operand::OperandType::kInteger;
  }

  double real_nb = str.toDouble(&ValidType);
  if (ValidType) {
    return Operand::OperandType::kReal;
  }

  if (str.indexOf("/") != -1) {
    QStringList list = str.split("/", QString::SkipEmptyParts);
    if (list.size() != 2) return Operand::OperandType::kUndefined;

    int_nb = list.at(0).toInt(&ValidType);
    if (!ValidType) return Operand::OperandType::kUndefined;

    int_nb = list.at(1).toInt(&ValidType);
    if (!ValidType) return Operand::OperandType::kUndefined;

    return Operand::OperandType::kFraction;
  }

  if (str.length() > 2 && str.at(0) == "'" && str.at(str.length() - 1) == "'") {
    if (ValidIdentifier(str.mid(1, str.length() - 2))) {
      return Operand::OperandType::kExpression;
    } else {
      throw(ComputerException("Invalid identicateur"));
    }
  }
  if (ValidIdentifier(str)) {
    return Operand::OperandType::kAtom;
  } else {
    throw(ComputerException("Invalid indenticateur"));
  }

  return Operand::OperandType::kUndefined;
}