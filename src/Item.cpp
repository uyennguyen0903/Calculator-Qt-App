#include "Item.h"

Literal& Item::GetLiteral() const {
  if (literal_ == nullptr)
    throw ComputerException(
        "Item : tentative d'acces a une expression inexistante");
  return *literal_;
}
