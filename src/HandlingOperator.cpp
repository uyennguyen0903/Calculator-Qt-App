#include "HandlingOperator.h"

Literal* STO::Compute(Integer& arg1, ExpressionLiteral& arg2) {
  arg2.GetAtom().SetValue(new Integer(&arg1));
  return nullptr;
}

Literal* STO::Compute(Real& arg1, ExpressionLiteral& arg2) {
  arg2.GetAtom().SetValue(new Real(&arg1));
  return nullptr;
}

Literal* STO::Compute(Fraction& arg1, ExpressionLiteral& arg2) {
  arg2.GetAtom().SetValue(new Fraction(&arg1));
  return nullptr;
}