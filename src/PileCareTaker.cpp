#include "PileCareTaker.h"

void PileCareTaker::BackUp() {
  pile_mementos_.push_back(pile_originator_->SaveStatus());
  atom_mementos_.push_back(atom_manager_.SaveStatus());
}

void PileCareTaker::Undo() {
  if (pile_mementos_.empty()) return;

  Pile* pile_memento = pile_mementos_.back();
  pile_mementos_.pop_back();
  pile_originator_->Restore(pile_memento);

  vector<pair<QString, Literal*> > atom_memento = atom_mementos_.back();
  atom_mementos_.pop_back();
  atom_manager_.Restore(atom_memento);
}
