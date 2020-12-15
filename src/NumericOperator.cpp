#include "NumericOperator.h"

Literal* AdditionOperator::Compute(const Integer& arg1, const Integer& arg2) {
  return new Integer(arg1.GetInt() + arg2.GetInt());
}

Literal* AdditionOperator::Compute(const Real& arg1, const Real& arg2) {
  return new Real(arg1.GetReal() + arg2.GetReal());
}

Literal* AdditionOperator::Compute(const Fraction& arg1, const Fraction& arg2) {
  int n1 = arg1.GetNumerator();
  int d1 = arg1.GetDenominator();
  int n2 = arg2.GetNumerator();
  int d2 = arg2.GetDenominator();
  Fraction* sum = new Fraction(n1 * d2 + n2 * d1, d1 * d2);
  if (sum->GetDenominator() == 1) {
    int sum_int = sum->GetNumerator();
    delete sum;
    return new Integer(sum_int);
  }
  return sum;
}

Literal* AdditionOperator::Compute(const Integer& arg1, const Real& arg2) {
  return new Real(double(arg1.GetInt()) + arg2.GetReal());
}

Literal* AdditionOperator::Compute(const Real& arg1, const Integer& arg2) {
  return Compute(arg2, arg1);
}

Literal* AdditionOperator::Compute(const Integer& arg1, const Fraction& arg2) {
  Fraction* sum =
      new Fraction(arg1.GetInt() * arg2.GetDenominator() + arg2.GetNumerator(),
                   arg2.GetDenominator());

  if (sum->GetDenominator() == 1) {
    int sum_int = sum->GetNumerator();
    delete sum;
    return new Integer(sum_int);
  }

  return sum;
}

Literal* AdditionOperator::Compute(const Fraction& arg1, const Integer& arg2) {
  return Compute(arg2, arg1);
}

Literal* AdditionOperator::Compute(const Real& arg1, const Fraction& arg2) {
  return new Real(arg1.GetReal() +
                  double(arg2.GetNumerator()) / double(arg2.GetDenominator()));
}

Literal* AdditionOperator::Compute(const Fraction& arg1, const Real& arg2) {
  return Compute(arg2, arg1);
}

Literal* STO::Compute(const Integer& arg1, const ExpressionLiteral& arg2) {
  arg2.GetAtom().SetValue(new Integer(arg1.GetInt()));
  return nullptr;
}

Literal* STO::Compute(const Real& arg1, const ExpressionLiteral& arg2) {
  arg2.GetAtom().SetValue(new Real(arg1.GetReal()));
  return nullptr;
}

Literal* STO::Compute(const Fraction& arg1, const ExpressionLiteral& arg2) {
  arg2.GetAtom().SetValue(
      new Fraction(arg1.GetNumerator(), arg1.GetDenominator()));
  return nullptr;
}