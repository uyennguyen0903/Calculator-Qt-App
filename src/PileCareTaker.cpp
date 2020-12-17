#include "PileCareTaker.h"

void PileCareTaker::BackUp() { mementos_.push_back(originator_->SaveStatus()); }

void PileCareTaker::Undo() {
  if (mementos_.empty()) return;
  Pile* memento = mementos_.back();
  mementos_.pop_back();
  originator_->Restore(memento);
}