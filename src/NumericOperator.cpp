#include "NumericOperator.h"

#include <iostream>

// Addition Operator.

void AdditionOperator::UpdatePile(Literal& arg1, Literal& arg2,
                                  Literal* const res,
                                  const QString& error_str) {
  if (error_str == "") {
    pile_.Push(literal_manager_.AddLiteral(res));
  } else {
    pile_.Push(arg1);
    pile_.Push(arg2);
  }
}

Literal* AdditionOperator::CastSameType(Literal& arg1, Literal& arg2) {
  Literal::LiteralType type = arg1.GetLiteralType();

  if (type == Literal::LiteralType::kInteger) {
    return Compute(dynamic_cast<Integer&>(arg1), dynamic_cast<Integer&>(arg2));
  }

  if (type == Literal::LiteralType::kReal) {
    return Compute(dynamic_cast<Real&>(arg1), dynamic_cast<Real&>(arg2));
  }

  if (type == Literal::LiteralType::kFraction) {
    return Compute(dynamic_cast<Fraction&>(arg1),
                   dynamic_cast<Fraction&>(arg2));
  }
}

Literal* AdditionOperator::Compute(Literal& arg1, Literal& arg2) {
  Literal::LiteralType type1 = arg1.GetLiteralType();
  Literal::LiteralType type2 = arg2.GetLiteralType();

  if (type1 == Literal::LiteralType::kExpression) {
    ExpressionLiteral& exp1 = dynamic_cast<ExpressionLiteral&>(arg1);
    return Compute(*exp1.GetAtom().CopyAtomValue(), arg2);
  }

  if (type2 == Literal::LiteralType::kExpression) {
    ExpressionLiteral& exp2 = dynamic_cast<ExpressionLiteral&>(arg2);
    return Compute(arg1, *exp2.GetAtom().CopyAtomValue());
  }

  if (type1 < type2 && type2 <= 2) {
    if (type2 == Literal::LiteralType::kFraction) {
      return CastSameType(*ConvertIntToFraction(arg1), arg2);
    }
    if (type2 == Literal::LiteralType::kReal) {
      return CastSameType(*ConvertToReal(arg1), arg2);
    }
  }

  if (type1 > type2 && type1 <= 2) {
    if (type1 == Literal::LiteralType::kFraction) {
      return CastSameType(arg1, *ConvertIntToFraction(arg2));
    }
    if (type1 == Literal::LiteralType::kReal) {
      return CastSameType(arg1, *ConvertToReal(arg2));
    }
  }

  if (type1 <= 2) {
    return CastSameType(arg1, arg2);
  }

  throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                          " entre " + arg1.Print() + " et " + arg2.Print()));
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

// ****************************************************************************
// ****************************************************************************
// ****************************************************************************
