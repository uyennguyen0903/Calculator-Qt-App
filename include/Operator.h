#ifndef OPERATOR_H_
#define OPERATOR_H_

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

  static const set<QString> kOperatorList;

  virtual const QString Print() const = 0;

  virtual void Execute() const = 0;
};

class AdditionOperator : public Operator {
 private:
  QString expression_ = "+";

 public:
  AdditionOperator() = default;

  const QString Print() const override { return expression_; }

  void Execute() const override;
};

#endif  // OPERATOR_H_