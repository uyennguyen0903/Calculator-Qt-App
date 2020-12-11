#include "Operator.h"

const set<string> Operator::operator_list_ = {
    "+",   "-",    "*",    "/",     "DIV", "NEG",   "=",   "!=",
    "=<",  ">=",   "<",    "<",     "AND", "OR",    "NOT", "EVAL",
    "DUP", "DROP", "SWAP", "CLEAR", "IFT", "FORGET"};