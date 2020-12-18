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
