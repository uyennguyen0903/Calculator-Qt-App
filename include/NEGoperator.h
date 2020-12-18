#ifndef NEG_OPERATOR_H_
#define NEG_OPERATOR_H_

#include "ComputerException.h"
#include "NumericLiteral.h"
#include "Operator.h"
#include "UnaryOperator.h"
#include "Utils.h"

class NegativeOperator : public UnaryOperator {
 private:
  QString expression_ = "NEG";

 public:
  NegativeOperator(LiteralManager& literal_manager, Pile& pile)
      : UnaryOperator(literal_manager, pile){};

  const QString Print() const override { return expression_; };

  Literal* Compute(Literal& arg) override;

  Literal* Compute(Integer& arg);
  Literal* Compute(Fraction& arg);
  Literal* Compute(Real& arg);
  Literal* Compute(ExpressionLiteral& arg);
};

#endif // NEG_OPERATOR_H_
