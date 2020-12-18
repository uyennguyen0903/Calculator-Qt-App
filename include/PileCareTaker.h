#ifndef PILE_CARE_TAKER_H_
#define PILE_CARE_TAKER_H_

#include <vector>

#include "Atom.h"
#include "AtomManager.h"
#include "Pile.h"

using namespace std;

class PileCareTaker {
 private:
  vector<Pile*> pile_mementos_;
  vector<vector<pair<QString, Literal*> > > atom_mementos_;
  Pile* pile_originator_;
  AtomManager& atom_manager_ = AtomManager::GetInstance();

 public:
  PileCareTaker(Pile* originator) : pile_originator_(originator){};

  void BackUp();

  void Undo();
};

#endif  // PILE_CARE_TAKER_H_