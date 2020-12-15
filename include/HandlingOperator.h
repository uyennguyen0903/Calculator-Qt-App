#ifndef HANDLING_OPERATOR_H_
#define HANDLING_OPERATOR_H_

#include "AtomManager.h"
#include "BinaryOperator.h"
#include "ComputerException.h"
#include "NumericLiteral.h"
#include "Operator.h"

class STO : public BinaryOperator {
 private:
  QString expression_ = "STO";
  AtomManager& atom_manager_ = AtomManager::GetInstance();

 public:
  STO(LiteralManager& literal_manager, Pile& pile)
      : BinaryOperator(literal_manager, pile){};

  const QString Print() const override { return expression_; }

  Literal* Compute(Integer& arg1, ExpressionLiteral& arg2) override;
  Literal* Compute(Real& arg1, ExpressionLiteral& arg2) override;
  Literal* Compute(Fraction& arg1, ExpressionLiteral& arg2) override;
  // TODO :  Implement Compute() method for 'Program'.
};

#endif  // HANDLING_OPERATOR_H