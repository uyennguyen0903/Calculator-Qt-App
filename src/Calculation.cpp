#include "Calculation.h"

Literal* Addition(const Integer& arg1, const Integer& arg2) {
  return new Integer(arg1.GetInt() + arg2.GetInt());
}

Literal* Addition(const Real& arg1, const Real& arg2) {
  return new Real(arg1.GetReal() + arg2.GetReal());
}

Literal* Addition(const Fraction& arg1, Fraction& arg2) {
  int n1 = arg1.GetNumerator();
  int d1 = arg1.GetDenominator();
  int n2 = arg2.GetNumerator();
  int d2 = arg2.GetDenominator();
  return new Fraction(n1 * d2 + n2 * d1, d1 * d2);
}

Literal* Addition(const Integer& arg1, const Real& arg2) {
  return new Real(double(arg1.GetInt()) + arg2.GetReal());
}

Literal* Addition(const Real& arg1, const Integer& arg2) {
  return Addition(arg2, arg1);
}

Literal* Addition(const Integer& arg1, const Fraction& arg2) {
  Fraction* sum =
      new Fraction(arg1.GetInt() * arg2.GetDenominator() + arg2.GetNumerator(),
                   arg2.GetDenominator());
  if (sum->GetDenominator() == 1) {
    return new Integer(sum->GetNumerator());
  } else {
    return sum;
  }
}

Literal* Addition(const Fraction& arg1, const Integer& arg2) {
  return Addition(arg2, arg1);
}

Literal* Addition(const Real& arg1, const Fraction& arg2) {
  return new Real(arg1.GetReal() +
                  double(arg2.GetNumerator() / arg2.GetDenominator()));
}

Literal* Addition(const Fraction& arg1, const Real& arg2) {
  return Addition(arg2, arg1);
}