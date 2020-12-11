#ifndef ITEM_H_
#define ITEM_H_

#include "ComputerException.h"
#include "LiteralManager.h"

class Item {
  Literal* literal_;

 public:
  Item() : literal_(nullptr) {}

  void SetLiteral(Literal& literal) { literal_ = &literal; }

  void SetLiteralNull() { literal_ = nullptr; }

  Literal& GetLiteral() const;
};

#endif  // ITEM_H_