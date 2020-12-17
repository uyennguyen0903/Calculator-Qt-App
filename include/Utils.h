#ifndef UTILS_H_
#define UTILS_H_

#include "ComputerException.h"
#include "Literal.h"
#include "NumericLiteral.h"
#include "Operand.h"
#include "Operator.h"

Operand::OperandType FindTypeOperand(const QString& str);

Fraction* ConvertIntToFraction(Literal& num);

Real* ConvertIntToReal(Literal& num);

Real* ConvertFractionToReal(Literal& frac);

Real* ConvertToReal(Literal& num);

#endif  // UTILS_H_