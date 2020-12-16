#include "NumericOperator.h"

#include <iostream>

// Addition Operator.

void AdditionOperator::UpdatePile(Literal& arg1, Literal& arg2,
                                  Literal* const res,
                                  const QString& error_str) {
  if (error_str == "") {
    //literal_manager_.RemoveLiteral(arg1);
    //literal_manager_.RemoveLiteral(arg2);
    pile_.Push(literal_manager_.AddLiteral(res));
  } else {
    pile_.Push(arg1);
    pile_.Push(arg2);
  }
}

Literal* AdditionOperator::Compute(Integer& arg1, Integer& arg2) {
  return new Integer(arg1.GetInt() + arg2.GetInt());
}

Literal* AdditionOperator::Compute(Real& arg1, Real& arg2) {
  return new Real(arg1.GetReal() + arg2.GetReal());
}

Literal* AdditionOperator::Compute(Fraction& arg1, Fraction& arg2) {
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

Literal* AdditionOperator::Compute(Integer& arg1, Real& arg2) {
  return new Real(double(arg1.GetInt()) + arg2.GetReal());
}

Literal* AdditionOperator::Compute(Real& arg1, Integer& arg2) {
  return Compute(arg2, arg1);
}

Literal* AdditionOperator::Compute(Integer& arg1, Fraction& arg2) {
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

Literal* AdditionOperator::Compute(Fraction& arg1, Integer& arg2) {
  return Compute(arg2, arg1);
}

Literal* AdditionOperator::Compute(Real& arg1, Fraction& arg2) {
  return new Real(arg1.GetReal() +
                  double(arg2.GetNumerator()) / double(arg2.GetDenominator()));
}

Literal* AdditionOperator::Compute(Fraction& arg1, Real& arg2) {
  return Compute(arg2, arg1);
}

// ****************************************************************************
// ****************************************************************************
// ****************************************************************************
