#include "UnaryOperator.h"

void UnaryOperator::Execute() {
  if (IsEnoughArguments(1)) {
    Literal& arg = pile_.Top();
    pile_.Pop();

    Literal* res = Compute(arg);

    pile_.Push(literal_manager_.AddLiteral(res));
  } else {
    throw(ComputerException("Pas assez argument."));
  }
}