#ifndef OPERATOR_H_
#define OPERATOR_H_

#include <iostream>
#include <set>

#include "Operand.h"

using namespace std;

class Operator : public Operand {
 public:
  Operator() = default;
  virtual ~Operator(){};
  static const set<string> operator_list_;
  virtual const string Print() const = 0;
};

class AdditionOperator : public Operator {
 private:
  string expression_ = "+";

 public:
  AdditionOperator() = default;
  string const Print() const override { return expression_; }
};

#endif  // OPERATOR_H_