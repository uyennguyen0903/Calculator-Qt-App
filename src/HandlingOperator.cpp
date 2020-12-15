#include "HandlingOperator.h"

void STO::UpdatePile(Literal& arg1, Literal& arg2, Literal* const res,
                     const QString& error_str) {
  if (error_str != "") {
    pile_.Push(arg1);
    pile_.Push(arg2);
  }
}

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