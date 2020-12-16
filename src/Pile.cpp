#include "Pile.h"

void Pile::Push(Literal& literal) {
  items_.push_back(Item());
  items_.back().SetLiteral(literal);
  ModifyStatus();
}

void Pile::Pop() {
  items_.back().SetLiteralNull();
  items_.pop_back();
  ModifyStatus();
}

Literal& Pile::Top() const { return items_.back().GetLiteral(); }

void Pile::Restore(Pile* const memento) { 
  items_ = memento->items_;
  nb_display_ = memento->GetNbDisplay();
  message_ = memento->GetMessage();
}
