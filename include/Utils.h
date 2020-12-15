#ifndef UTILS_H_
#define UTILS_H_

#include "Operand.h"
#include "Operator.h"
#include "Literal.h"
#include "NumericLiteral.h"
#include "ComputerException.h"

Operand::OperandType FindTypeOperand(const QString& str);

#endif  // UTILS_H_