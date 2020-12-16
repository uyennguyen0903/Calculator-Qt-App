#ifndef PILE_CARE_TAKER_H_
#define PILE_CARE_TAKER_H_

#include <vector>

#include "Pile.h"

using namespace std;

class PileCareTaker {
 private:
  vector<Pile*> mementos_;
  Pile* originator_;

 public:
  PileCareTaker(Pile* originator) : originator_(originator){};

  void BackUp();

  void Undo();
};

#endif  // PILE_CARE_TAKER_H_