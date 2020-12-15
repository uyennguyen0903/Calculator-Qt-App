#ifndef NUMERIC_OPERATOR_H_
#define NUMERIC_OPERATOR_H_

#include "AtomManager.h"
#include "BinaryOperator.h"
#include "ComputerException.h"
#include "NumericLiteral.h"
#include "Operator.h"

class AdditionOperator : public BinaryOperator {
 private:
  QString expression_ = "+";

 public:
  AdditionOperator(LiteralManager& literal_manager, Pile& pile)
      : BinaryOperator(literal_manager, pile){};

  const QString Print() const override { return expression_; }

  void UpdatePile(Literal& arg1, Literal& arg2, Literal* res, const QString& error_str) override;

  Literal* Compute(Integer& arg1, Integer& arg2) override;
  Literal* Compute(Real& arg1, Real& arg2) override;
  Literal* Compute(Fraction& arg1, Fraction& arg2) override;
  Literal* Compute(Integer& arg1, Real& arg2) override;
  Literal* Compute(Real& arg1, Integer& arg2) override;
  Literal* Compute(Integer& arg1, Fraction& arg2) override;
  Literal* Compute(Fraction& arg1, Integer& arg2) override;
  Literal* Compute(Real& arg1, Fraction& arg2) override;
  Literal* Compute(Fraction& arg1, Real& arg2) override;
  // TODO : Implement Compute() method for 'Atom' & 'Program'.
};

#endif  // NUMERIC_OPERATOR_H