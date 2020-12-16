#include "BinaryOperator.h"

void BinaryOperator::Execute() {
  if (IsEnoughArguments(2)) {
    Literal& arg2 = pile_.Top();
    pile_.Pop();
    Literal& arg1 = pile_.Top();
    pile_.Pop();
    Literal* res = nullptr;
    QString error_str = "";
    try {
      res = CastFirstArg(arg1, arg2);
    } catch (ComputerException& error) {
      error_str = error.GetInfo();
    }
    UpdatePile(arg1, arg2, res, error_str);
    if (error_str != "") throw ComputerException(error_str);
  } else {
    throw(ComputerException("Pas assez argument."));
  }
}

Literal* BinaryOperator::CastFirstArg(Literal& arg1, Literal& arg2) {
  if (arg1.GetLiteralType() == Literal::LiteralType::kInteger)
    return CastSecondArg<Integer>(dynamic_cast<Integer&>(arg1), arg2);
  if (arg1.GetLiteralType() == Literal::LiteralType::kFraction)
    return CastSecondArg<Fraction>(dynamic_cast<Fraction&>(arg1), arg2);
  if (arg1.GetLiteralType() == Literal::LiteralType::kReal)
    return CastSecondArg<Real>(dynamic_cast<Real&>(arg1), arg2);
  if (arg1.GetLiteralType() == Literal::LiteralType::kExpression)
    return CastSecondArg<ExpressionLiteral>(
        dynamic_cast<ExpressionLiteral&>(arg1), arg2);
  if (arg1.GetLiteralType() == Literal::LiteralType::kProgram)
    return CastSecondArg<Program>(dynamic_cast<Program&>(arg1), arg2);
  return nullptr;
}

template <class T>
Literal* BinaryOperator::CastSecondArg(T& arg1, Literal& arg2) {
  if (arg2.GetLiteralType() == Literal::LiteralType::kInteger)
    return Compute(arg1, dynamic_cast<Integer&>(arg2));
  if (arg2.GetLiteralType() == Literal::LiteralType::kFraction)
    return Compute(arg1, dynamic_cast<Fraction&>(arg2));
  if (arg2.GetLiteralType() == Literal::LiteralType::kReal)
    return Compute(arg1, dynamic_cast<Real&>(arg2));
  if (arg2.GetLiteralType() == Literal::LiteralType::kExpression)
    return Compute(arg1, dynamic_cast<ExpressionLiteral&>(arg2));
  if (arg2.GetLiteralType() == Literal::LiteralType::kProgram)
    return Compute(arg1, dynamic_cast<Program&>(arg2));
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

Literal* BinaryOperator::Compute(Program& arg1, Program& arg2) {
  throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                          " entre " + arg1.Print() + " et " + arg2.Print()));
}
Literal* BinaryOperator::Compute(Integer& arg1, Program& arg2) {
  throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                          " entre " + arg1.Print() + " et " + arg2.Print()));
}
Literal* BinaryOperator::Compute(Real& arg1, Program& arg2) {
  throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                          " entre " + arg1.Print() + " et " + arg2.Print()));
}
Literal* BinaryOperator::Compute(Fraction& arg1, Program& arg2) {
  throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                          " entre " + arg1.Print() + " et " + arg2.Print()));
}
Literal* BinaryOperator::Compute(ExpressionLiteral& arg1, Program& arg2) {
  throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                          " entre " + arg1.Print() + " et " + arg2.Print()));
}
Literal* BinaryOperator::Compute(Program& arg1, ExpressionLiteral& arg2) {
  throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                          " entre " + arg1.Print() + " et " + arg2.Print()));
}
Literal* BinaryOperator::Compute(Program& arg1, Integer& arg2) {
  throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                          " entre " + arg1.Print() + " et " + arg2.Print()));
}
Literal* BinaryOperator::Compute(Program& arg1, Real& arg2) {
  throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                          " entre " + arg1.Print() + " et " + arg2.Print()));
}
Literal* BinaryOperator::Compute(Program& arg1, Fraction& arg2) {
  throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                          " entre " + arg1.Print() + " et " + arg2.Print()));
}

Literal* BinaryOperator::Compute(Integer& arg1, ExpressionLiteral& arg2) {
  Literal* exp_value = arg2.GetAtom().CopyAtomValue();
  if (exp_value != nullptr) {
    return CastFirstArg(arg1, *exp_value);
  } else {
    throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                            " entre " + arg1.Print() + " et " + arg2.Print()));
  }
}

Literal* BinaryOperator::Compute(Fraction& arg1, ExpressionLiteral& arg2) {
  Literal* exp_value = arg2.GetAtom().CopyAtomValue();
  if (exp_value != nullptr) {
    return CastFirstArg(arg1, *exp_value);
  } else {
    throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                            " entre " + arg1.Print() + " et " + arg2.Print()));
  }
}

Literal* BinaryOperator::Compute(Real& arg1, ExpressionLiteral& arg2) {
  Literal* exp_value = arg2.GetAtom().CopyAtomValue();
  if (exp_value != nullptr) {
    return CastFirstArg(arg1, *exp_value);
  } else {
    throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                            " entre " + arg1.Print() + " et " + arg2.Print()));
  }
}

Literal* BinaryOperator::Compute(ExpressionLiteral& arg1, Integer& arg2) {
  Literal* exp_value = arg1.GetAtom().CopyAtomValue();
  if (exp_value != nullptr) {
    return CastFirstArg(*exp_value, arg2);
  } else {
    throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                            " entre " + arg1.Print() + " et " + arg2.Print()));
  }
}

Literal* BinaryOperator::Compute(ExpressionLiteral& arg1, Real& arg2) {
  Literal* exp_value = arg1.GetAtom().CopyAtomValue();
  if (exp_value != nullptr) {
    return CastFirstArg(*exp_value, arg2);
  } else {
    throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                            " entre " + arg1.Print() + " et " + arg2.Print()));
  }
}

Literal* BinaryOperator::Compute(ExpressionLiteral& arg1, Fraction& arg2) {
  Literal* exp_value = arg1.GetAtom().CopyAtomValue();
  if (exp_value != nullptr) {
    return CastFirstArg(*exp_value, arg2);
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
    return CastFirstArg(*exp_value1, *exp_value2);
  } else {
    throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                            " entre " + arg1.Print() + " et " + arg2.Print()));
  }
}
