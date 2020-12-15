#include "BinaryOperator.h"

Literal* BinaryOperator::CastLiteral(Literal& arg1, Literal& arg2) {
  if (arg1.GetLiteralType() == Literal::LiteralType::kInteger &&
      arg2.GetLiteralType() == Literal::LiteralType::kInteger) {
    return Compute(dynamic_cast<Integer&>(arg1), dynamic_cast<Integer&>(arg2));
  }

  if (arg1.GetLiteralType() == Literal::LiteralType::kReal &&
      arg2.GetLiteralType() == Literal::LiteralType::kReal) {
    return Compute(dynamic_cast<Real&>(arg1), dynamic_cast<Real&>(arg2));
  }

  if (arg1.GetLiteralType() == Literal::LiteralType::kFraction &&
      arg2.GetLiteralType() == Literal::LiteralType::kFraction) {
    return Compute(dynamic_cast<Fraction&>(arg1),
                   dynamic_cast<Fraction&>(arg2));
  }

  if (arg1.GetLiteralType() == Literal::LiteralType::kInteger &&
      arg2.GetLiteralType() == Literal::LiteralType::kReal) {
    return Compute(dynamic_cast<Integer&>(arg1), dynamic_cast<Real&>(arg2));
  }

  if (arg1.GetLiteralType() == Literal::LiteralType::kInteger &&
      arg2.GetLiteralType() == Literal::LiteralType::kFraction) {
    return Compute(dynamic_cast<Integer&>(arg1), dynamic_cast<Fraction&>(arg2));
  }

  if (arg1.GetLiteralType() == Literal::LiteralType::kFraction &&
      arg2.GetLiteralType() == Literal::LiteralType::kReal) {
    return Compute(dynamic_cast<Fraction&>(arg1), dynamic_cast<Real&>(arg2));
  }

  if (arg1.GetLiteralType() == Literal::LiteralType::kReal &&
      arg2.GetLiteralType() == Literal::LiteralType::kInteger) {
    return Compute(dynamic_cast<Real&>(arg1), dynamic_cast<Integer&>(arg2));
  }

  if (arg1.GetLiteralType() == Literal::LiteralType::kFraction &&
      arg2.GetLiteralType() == Literal::LiteralType::kInteger) {
    return Compute(dynamic_cast<Fraction&>(arg1), dynamic_cast<Integer&>(arg2));
  }

  if (arg1.GetLiteralType() == Literal::LiteralType::kReal &&
      arg2.GetLiteralType() == Literal::LiteralType::kFraction) {
    return Compute(dynamic_cast<Real&>(arg1), dynamic_cast<Fraction&>(arg2));
  }

  if (arg1.GetLiteralType() == Literal::LiteralType::kExpression &&
      arg2.GetLiteralType() == Literal::LiteralType::kExpression) {
    return Compute(dynamic_cast<ExpressionLiteral&>(arg1),
                   dynamic_cast<ExpressionLiteral&>(arg2));
  }

  if (arg1.GetLiteralType() == Literal::LiteralType::kExpression &&
      arg2.GetLiteralType() == Literal::LiteralType::kInteger) {
    return Compute(dynamic_cast<ExpressionLiteral&>(arg1),
                   dynamic_cast<Integer&>(arg2));
  }

  if (arg1.GetLiteralType() == Literal::LiteralType::kExpression &&
      arg2.GetLiteralType() == Literal::LiteralType::kReal) {
    return Compute(dynamic_cast<ExpressionLiteral&>(arg1),
                   dynamic_cast<Real&>(arg2));
  }

  if (arg1.GetLiteralType() == Literal::LiteralType::kExpression &&
      arg2.GetLiteralType() == Literal::LiteralType::kFraction) {
    return Compute(dynamic_cast<ExpressionLiteral&>(arg1),
                   dynamic_cast<Fraction&>(arg2));
  }

  if (arg1.GetLiteralType() == Literal::LiteralType::kInteger &&
      arg2.GetLiteralType() == Literal::LiteralType::kExpression) {
    return Compute(dynamic_cast<Integer&>(arg1),
                   dynamic_cast<ExpressionLiteral&>(arg2));
  }

  if (arg1.GetLiteralType() == Literal::LiteralType::kReal &&
      arg2.GetLiteralType() == Literal::LiteralType::kExpression) {
    return Compute(dynamic_cast<Real&>(arg1),
                   dynamic_cast<ExpressionLiteral&>(arg2));
  }

  if (arg1.GetLiteralType() == Literal::LiteralType::kFraction &&
      arg2.GetLiteralType() == Literal::LiteralType::kExpression) {
    return Compute(dynamic_cast<Fraction&>(arg1),
                   dynamic_cast<ExpressionLiteral&>(arg2));
  }

  return nullptr;
}

Literal* BinaryOperator::Compute(Integer& arg1, Integer& arg2) {
  throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                          " entre " + arg1.Print() + " et " + arg2.Print()));
}

Literal* BinaryOperator::Compute(Real& arg1, Real& arg2) {
  throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                          " entre " + arg1.Print() + " et " + arg2.Print()));
}

Literal* BinaryOperator::Compute(Fraction& arg1, Fraction& arg2) {
  throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                          " entre " + arg1.Print() + " et " + arg2.Print()));
}

Literal* BinaryOperator::Compute(Integer& arg1, Real& arg2) {
  throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                          " entre " + arg1.Print() + " et " + arg2.Print()));
}

Literal* BinaryOperator::Compute(Real& arg1, Integer& arg2) {
  throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                          " entre " + arg1.Print() + " et " + arg2.Print()));
}

Literal* BinaryOperator::Compute(Integer& arg1, Fraction& arg2) {
  throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                          " entre " + arg1.Print() + " et " + arg2.Print()));
}

Literal* BinaryOperator::Compute(Fraction& arg1, Integer& arg2) {
  throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                          " entre " + arg1.Print() + " et " + arg2.Print()));
}

Literal* BinaryOperator::Compute(Real& arg1, Fraction& arg2) {
  throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                          " entre " + arg1.Print() + " et " + arg2.Print()));
}

Literal* BinaryOperator::Compute(Fraction& arg1, Real& arg2) {
  throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                          " entre " + arg1.Print() + " et " + arg2.Print()));
}

Literal* BinaryOperator::Compute(Integer& arg1, ExpressionLiteral& arg2) {
  Literal* exp_value = arg2.GetAtom().CopyAtomValue();
  if (exp_value != nullptr) {
    return CastLiteral(arg1, *exp_value);
  } else {
    throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                            " entre " + arg1.Print() + " et " + arg2.Print()));
  }
}

Literal* BinaryOperator::Compute(Fraction& arg1, ExpressionLiteral& arg2) {
  Literal* exp_value = arg2.GetAtom().CopyAtomValue();
  if (exp_value != nullptr) {
    return CastLiteral(arg1, *exp_value);
  } else {
    throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                            " entre " + arg1.Print() + " et " + arg2.Print()));
  }
}

Literal* BinaryOperator::Compute(Real& arg1, ExpressionLiteral& arg2) {
  Literal* exp_value = arg2.GetAtom().CopyAtomValue();
  if (exp_value != nullptr) {
    return CastLiteral(arg1, *exp_value);
  } else {
    throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                            " entre " + arg1.Print() + " et " + arg2.Print()));
  }
}

Literal* BinaryOperator::Compute(ExpressionLiteral& arg1, Integer& arg2) {
  Literal* exp_value = arg1.GetAtom().CopyAtomValue();
  if (exp_value != nullptr) {
    return CastLiteral(*exp_value, arg2);
  } else {
    throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                            " entre " + arg1.Print() + " et " + arg2.Print()));
  }
}

Literal* BinaryOperator::Compute(ExpressionLiteral& arg1, Real& arg2) {
  Literal* exp_value = arg1.GetAtom().CopyAtomValue();
  if (exp_value != nullptr) {
    return CastLiteral(*exp_value, arg2);
  } else {
    throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                            " entre " + arg1.Print() + " et " + arg2.Print()));
  }
}

Literal* BinaryOperator::Compute(ExpressionLiteral& arg1, Fraction& arg2) {
  Literal* exp_value = arg1.GetAtom().CopyAtomValue();
  if (exp_value != nullptr) {
    return CastLiteral(*exp_value, arg2);
  } else {
    throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                            " entre " + arg1.Print() + " et " + arg2.Print()));
  }
}

Literal* BinaryOperator::Compute(ExpressionLiteral& arg1,
                                 ExpressionLiteral& arg2) {
  Literal* exp_value1 = arg1.GetAtom().CopyAtomValue();
  Literal* exp_value2 = arg2.GetAtom().CopyAtomValue();
  if (exp_value1 != nullptr && exp_value2 != nullptr) {
    return CastLiteral(*exp_value1, *exp_value2);
  } else {
    throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                            " entre " + arg1.Print() + " et " + arg2.Print()));
  }
}

void BinaryOperator::Execute() {
  if (IsEnoughArguments(2)) {
    Literal& arg2 = pile_.Top();
    pile_.Pop();
    Literal& arg1 = pile_.Top();
    pile_.Pop();
    Literal* res = nullptr;
    QString error_str = "";
    try {
      res = CastLiteral(arg1, arg2);
    } catch (ComputerException& error) {
      error_str = error.GetInfo();
    }
    UpdatePile(arg1, arg2, res, error_str);
    if (error_str != "") throw ComputerException(error_str);
  } else {
    throw(ComputerException("Pas assez argument."));
  }
}
