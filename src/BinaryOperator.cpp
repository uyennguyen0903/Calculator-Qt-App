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

Literal* BinaryOperator::Compute(const Integer& arg1, const Integer& arg2) {
  throw(ComputerException("Arguments sont invalids."));
}

Literal* BinaryOperator::Compute(const Real& arg1, const Real& arg2) {
  throw(ComputerException("Arguments sont invalids."));
}

Literal* BinaryOperator::Compute(const Fraction& arg1, const Fraction& arg2) {
  throw(ComputerException("Arguments sont invalids."));
}

Literal* BinaryOperator::Compute(const Integer& arg1, const Real& arg2) {
  throw(ComputerException("Arguments sont invalids."));
}

Literal* BinaryOperator::Compute(const Real& arg1, const Integer& arg2) {
  throw(ComputerException("Arguments sont invalids."));
}

Literal* BinaryOperator::Compute(const Integer& arg1, const Fraction& arg2) {
  throw(ComputerException("Arguments sont invalids."));
}

Literal* BinaryOperator::Compute(const Fraction& arg1, const Integer& arg2) {
  throw(ComputerException("Arguments sont invalids."));
}

Literal* BinaryOperator::Compute(const Real& arg1, const Fraction& arg2) {
  throw(ComputerException("Arguments sont invalids."));
}

Literal* BinaryOperator::Compute(const Fraction& arg1, const Real& arg2) {
  throw(ComputerException("Arguments sont invalids."));
}

Literal* BinaryOperator::Compute(const Integer& arg1,
                                 const ExpressionLiteral& arg2) {
  throw(ComputerException("Arguments sont invalids."));
}
Literal* BinaryOperator::Compute(const Fraction& arg1,
                                 const ExpressionLiteral& arg2) {
  throw(ComputerException("Arguments sont invalids."));
}
Literal* BinaryOperator::Compute(const Real& arg1,
                                 const ExpressionLiteral& arg2) {
  throw(ComputerException("Arguments sont invalids."));
}

Literal* BinaryOperator::Compute(const ExpressionLiteral& arg1,
                                 const Integer& arg2) {
  throw(ComputerException("Arguments sont invalids."));
}

Literal* BinaryOperator::Compute(const ExpressionLiteral& arg1,
                                 const Real& arg2) {
  throw(ComputerException("Arguments sont invalids."));
}

Literal* BinaryOperator::Compute(const ExpressionLiteral& arg1,
                                 const Fraction& arg2) {
  throw(ComputerException("Arguments sont invalids."));
}

Literal* BinaryOperator::Compute(const ExpressionLiteral& arg1,
                                 const ExpressionLiteral& arg2) {
  throw(ComputerException("Arguments sont invalids."));
}

void BinaryOperator::Execute() {
  if (IsEnoughArguments(2)) {
    Literal& arg2 = pile_.Top();
    pile_.Pop();
    Literal& arg1 = pile_.Top();
    pile_.Pop();

    Literal* res = CastLiteral(arg1, arg2);

    literal_manager_.RemoveLiteral(arg1);
    literal_manager_.RemoveLiteral(arg2);
    if (res != nullptr) pile_.Push(literal_manager_.AddLiteral(res));
  } else {
    throw(ComputerException("Pas assez argument."));
  }
}
