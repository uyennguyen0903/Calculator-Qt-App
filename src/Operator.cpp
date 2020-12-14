#include "Operator.h"

const set<QString> Operator::kOperatorList = {
    "+",   "-",    "*",    "/",     "DIV", "NEG",    "=",   "!=",
    "=<",  ">=",   "<",    "<",     "AND", "OR",     "NOT", "EVAL",
    "DUP", "DROP", "SWAP", "CLEAR", "IFT", "FORGET", "STO"};

bool Operator::IsEnoughArguments(size_t n) const {
  if (pile_.GetPileSize() < n) {
    pile_.SetMessage("Erreur : pas assez d'arguments");
    return false;
  }
  return true;
}

Literal* Operator::CastLiteral(Literal& arg1, Literal& arg2) {
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

  return nullptr;
}

void Operator::Execute() {
  if (IsEnoughArguments(2)) {
    Literal& arg1 = pile_.Top();
    pile_.Pop();
    Literal& arg2 = pile_.Top();
    pile_.Pop();

    Literal* res = CastLiteral(arg1, arg2);

    literal_manager_.RemoveLiteral(arg1);
    literal_manager_.RemoveLiteral(arg2);
    pile_.Push(literal_manager_.AddLiteral(res));
  }
}

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
  return new Fraction(n1 * d2 + n2 * d1, d1 * d2);
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
    return new Integer(sum->GetNumerator());
  } else {
    return sum;
  }
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