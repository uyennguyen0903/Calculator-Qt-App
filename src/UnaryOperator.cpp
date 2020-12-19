#include "UnaryOperator.h"

void UnaryOperator::Execute() {
  if (IsEnoughArguments(1)) {
    Literal& arg = pile_.Top();
    pile_.Pop();

    Literal* res = SimplifyResult(Compute(arg));

    pile_.Push(literal_manager_.AddLiteral(res));
  } else {
    throw(ComputerException("Pas assez argument."));
  }
}

// ****************************************************************************
// ****************************************************************************

// NEG operator.

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
                          " sur " + arg.Print()));
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
  Literal* value = arg.GetAtom().CopyAtomValue();
  if (value == nullptr) {
    throw(ComputerException("Atome/Expression n'a pas value associée."));
  }

  arg.GetAtom().SetValue(Compute(*value));

  return new ExpressionLiteral(arg.Print(), arg.GetAtom());
}

// ****************************************************************************
// ****************************************************************************

// NOT operator.

Literal* Not::Compute(Literal& arg) {
  if (LogicTest(&arg))
    return new Integer(long(0));
  else
    return new Integer(long(1));
}

// ****************************************************************************
// ****************************************************************************

// NUM, DEN operator.

Literal* NumDen::Compute(Literal& arg) {
  Literal::LiteralType type = arg.GetLiteralType();

  if (type == Literal::LiteralType::kInteger) {
    return Compute(dynamic_cast<Integer&>(arg));
  }

  if (type == Literal::LiteralType::kFraction) {
    return Compute(dynamic_cast<Fraction&>(arg));
  }

  if (type == Literal::LiteralType::kExpression) {
    return Compute(dynamic_cast<ExpressionLiteral&>(arg));
  }

  throw(ComputerException("Impossible d'effectuer cet opérateur sur " +
                          arg.Print()));
}

Literal* NumDen::Compute(Integer& arg) {
  if (num_) {
    return new Integer(arg.GetInt());
  } else {
    return new Integer(long(1));
  }
}

Literal* NumDen::Compute(Fraction& arg) {
  if (num_) {
    return new Integer(arg.GetNumerator());
  } else {
    return new Integer(arg.GetDenominator());
  }
}

Literal* NumDen::Compute(ExpressionLiteral& arg) {
  Literal* value = arg.GetAtom().CopyAtomValue();
  if (value == nullptr) {
    throw(ComputerException("Atome/Expression n'a pas value associée."));
  }
  return Compute(*value);
}