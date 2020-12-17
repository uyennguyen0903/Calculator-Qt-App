#ifndef UNARY_OPERATOR_H_
#define UNARY_OPERATOR_H_

#include "AtomManager.h"
#include "ComputerException.h"
#include "NumericLiteral.h"
#include "Operator.h"
#include "Program.h"

class UnaryOperator : public Operator {
 public:
  UnaryOperator(LiteralManager& literal_manager, Pile& pile)
      : Operator(literal_manager, pile){};

  virtual ~UnaryOperator(){};

  void Execute() override;

  virtual const QString Print() const = 0;

  virtual Literal* Compute(Literal& arg) = 0;
};

#endif  // UNARY_OPERATOR_H