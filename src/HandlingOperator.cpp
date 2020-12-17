#include "HandlingOperator.h"

#include <iostream>

void STO::UpdatePile(Literal& arg1, Literal& arg2, Literal* const res,
                     const QString& error_str) {
  if (error_str != "") {
    pile_.Push(arg1);
    pile_.Push(arg2);
  }
}

Literal* STO::Compute(Literal& arg1, Literal& arg2) {
  if (arg2.GetLiteralType() == Literal::LiteralType::kExpression) {
    Literal::LiteralType type1 = arg1.GetLiteralType();

    if (type1 == Literal::LiteralType::kInteger) {
      return Compute(dynamic_cast<Integer&>(arg1),
                     dynamic_cast<ExpressionLiteral&>(arg2));
    }

    if (type1 == Literal::LiteralType::kFraction) {
      return Compute(dynamic_cast<Fraction&>(arg1),
                     dynamic_cast<ExpressionLiteral&>(arg2));
    }

    if (type1 == Literal::LiteralType::kReal) {
      return Compute(dynamic_cast<Real&>(arg1),
                     dynamic_cast<ExpressionLiteral&>(arg2));
    }

    if (type1 == Literal::LiteralType::kProgram) {
      return Compute(dynamic_cast<Program&>(arg1),
                     dynamic_cast<ExpressionLiteral&>(arg2));
    }
  }

  throw(ComputerException("Impossible d'effectuer l'opération " + Print() +
                          " entre " + arg1.Print() + " et " + arg2.Print()));
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

Literal* STO::Compute(Program& arg1, ExpressionLiteral& arg2) {
  arg2.GetAtom().SetValue(new Program(&arg1));
  return nullptr;
}