#include "Operator.h"

const set<QString> Operator::operator_list_ = {
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

void Operator::Execute() const {
  if (IsEnoughArguments(2)) {
    Integer& arg1 = dynamic_cast<Integer&>(pile_.Top());
    pile_.Pop();
    Integer& arg2 = dynamic_cast<Integer&>(pile_.Top());
    pile_.Pop();
    Literal* res = new Integer(arg1.GetInt() + arg2.GetInt());
    literal_manager_.RemoveLiteral(arg1);
    literal_manager_.RemoveLiteral(arg2);
    literal_manager_.AddLiteral(res);
  }
}