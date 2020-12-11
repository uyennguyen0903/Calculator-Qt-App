#ifndef OPERATOR_H_
#define OPERATOR_H_

#include <iostream>
#include <set>

#include "Literal.h"
#include "NumericLiteral.h"
#include "Operand.h"
#include "Pile.h"

using namespace std;

class Operator : public Operand {
 protected:
  LiteralManager& literal_manager_;
  Pile& pile_;

  bool IsEnoughArguments(size_t n) const;

 public:
  Operator(LiteralManager& literal_manager, Pile& pile)
      : literal_manager_(literal_manager), pile_(pile){};

  virtual ~Operator(){};

  static const set<string> operator_list_;

  virtual const string Print() const = 0;

  virtual void Execute() const = 0;
};

class AdditionOperator : public Operator {
 private:
  string expression_ = "+";

 public:
  AdditionOperator() = default;

  string const Print() const override { return expression_; }

  void Execute() const override;
};

#endif  // OPERATOR_H_