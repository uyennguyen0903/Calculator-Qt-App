#include "Operator.h"

const set<QString> Operator::kOperatorList = {
    "+",    "-",   "*",    "/",    "DIV",   "MOD", "NEG",    "=",
    "!=",   "<=",  ">=",   "<",    ">",     "AND", "OR",     "NOT",
    "EVAL", "DUP", "DROP", "SWAP", "CLEAR", "IFT", "FORGET", "STO"};

bool Operator::IsEnoughArguments(size_t n) const {
  if (pile_.GetPileSize() < n) {
    pile_.SetMessage("Erreur : pas assez d'arguments");
    return false;
  }
  return true;
}

Literal* Operator::SimplifyResult(Literal* const res) {
  if (res == nullptr) return nullptr;

  Literal::LiteralType type = res->GetLiteralType();

  if (type == Literal::LiteralType::kFraction) {
    Fraction* frac = dynamic_cast<Fraction*>(res);
    if (frac->GetNumerator() == 0) {
      return new Integer(long(0));
    }
    if (frac->GetDenominator() == 1) {
      return new Integer(frac->GetNumerator());
    }
  }

  if (type == Literal::LiteralType::kReal) {
    Real* reel = dynamic_cast<Real*>(res);
    float val = reel->GetReal();
    if (val == trunc(val)) {
      return new Integer(trunc(val));
    }
  }

  return res;
}
