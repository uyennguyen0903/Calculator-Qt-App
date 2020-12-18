#include "NEGoperator.h"

Literal* NegativeOperator::Compute(Literal& arg) {
  Literal::LiteralType type = arg.GetLiteralType();

  if (type == Literal::LiteralType::kInteger) {
    return Compute(dynamic_cast<Integer&>(arg));
  }

  if (type == Literal::LiteralType::kReal) {
    return Compute(dynamic_cast<Real&>(arg));
  }

  if (type == Literal::LiteralType::kFraction) {
    return Compute(dynamic_cast<Fraction&>(arg));
  }

  if (type == Literal::LiteralType::kExpression) {
    return Compute(dynamic_cast<ExpressionLiteral&>(arg));
  }

  throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                          " entre " + arg.Print()));
}

Literal* NegativeOperator::Compute(Integer& arg) {
  return new Integer(arg.GetInt() * -1);
}

Literal* NegativeOperator::Compute(Fraction& arg) {
  return new Fraction(arg.GetNumerator() * -1, arg.GetDenominator());
}

Literal* NegativeOperator::Compute(Real& arg) {
  return new Real(arg.GetReal() * -1.0);
}

Literal* NegativeOperator::Compute(ExpressionLiteral& arg) {
  if (arg.GetLiteralType() == Literal::LiteralType::kProgram) {
    throw(ComputerException("Impossible de changer la signe d'une programme."));
  }

  Literal* value = arg.GetAtom().CopyAtomValue();
  if (value == nullptr) {
    throw(ComputerException("Atome/Expression n'a pas value associée."));
  }

  arg.GetAtom().SetValue(Compute(*value));

  return new ExpressionLiteral(arg.Print(), arg.GetAtom());
}
