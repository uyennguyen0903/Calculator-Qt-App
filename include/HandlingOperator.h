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

  void UpdatePile(Literal& arg1, Literal& arg2, Literal* const res,
                  const QString& error_str) override;

  const QString Print() const override { return expression_; }

  Literal* Compute(Integer& arg1, ExpressionLiteral& arg2) override;
  Literal* Compute(Real& arg1, ExpressionLiteral& arg2) override;
  Literal* Compute(Fraction& arg1, ExpressionLiteral& arg2) override;
  Literal* Compute(Program& arg1, ExpressionLiteral& arg2) override;
};

#endif  // HANDLING_OPERATOR_H