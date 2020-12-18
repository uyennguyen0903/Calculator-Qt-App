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
      res = Compute(arg1, arg2);
    } catch (ComputerException& error) {
      error_str = error.GetInfo();
    }
    UpdatePile(arg1, arg2, res, error_str);
    if (error_str != "") throw ComputerException(error_str);
  } else {
    throw(ComputerException("Pas assez argument."));
  }
}
