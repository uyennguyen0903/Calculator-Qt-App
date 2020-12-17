#ifndef BINARY_OPERATOR_H_
#define BINARY_OPERATOR_H_

#include "AtomManager.h"
#include "ComputerException.h"
#include "NumericLiteral.h"
#include "Operator.h"
#include "Program.h"

class BinaryOperator : public Operator {
 public:
  BinaryOperator(LiteralManager& literal_manager, Pile& pile)
      : Operator(literal_manager, pile){};

  virtual ~BinaryOperator(){};

  void Execute() override;

  virtual void UpdatePile(Literal& arg1, Literal& arg, Literal* res,
                          const QString& error_str) = 0;

  virtual const QString Print() const = 0;

  virtual Literal* Compute(Literal& arg1, Literal& arg2) = 0;
};

#endif  // BINARY_OPERATOR_H