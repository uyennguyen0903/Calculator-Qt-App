#ifndef PILE_H_
#define PILE_H_

#include <vector>

#include "Item.h"

using namespace std;

class Pile {
 private:
  vector<Item> items_;
  string message_;
  size_t nb_display_;

 public:
  Pile() : message_(""), nb_display_(5){};

  ~Pile();

  void Push(Literal& literal);

  void Pop();

  Literal& Top() const;

  void SetNbDisplay(size_t nb) { nb_display_ = nb; }

  size_t GetNbDisplay() const { return nb_display_; }

  void SetMessage(string message) { message_ = message; }

  string GetMessage() const { return message_; }

  size_t GetPileSize() const { return items_.size(); }
};

#endif  // PILE_H_