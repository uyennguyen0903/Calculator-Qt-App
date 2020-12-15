#ifndef BINARY_OPERATOR_H_
#define BINARY_OPERATOR_H_

#include <iostream>

#include "AtomManager.h"
#include "ComputerException.h"
#include "NumericLiteral.h"
#include "Operator.h"

class BinaryOperator : public Operator {
 public:
  BinaryOperator(LiteralManager& literal_manager, Pile& pile)
      : Operator(literal_manager, pile){};

  virtual ~BinaryOperator(){};

  void Execute() override;

  virtual void UpdatePile(Literal& arg1, Literal& arg, Literal* res,
                          const QString& error_str) = 0;

  Literal* CastFirstArg(Literal& arg1, Literal& arg2);

  Literal* CastSecondArg(Integer& arg1, Literal& arg2);

  Literal* CastSecondArg(Real& arg1, Literal& arg2);

  Literal* CastSecondArg(Fraction& arg1, Literal& arg2);

  Literal* CastSecondArg(ExpressionLiteral& arg1, Literal& arg2);

  virtual const QString Print() const = 0;

  virtual Literal* Compute(Integer& arg1, Integer& arg2);
  virtual Literal* Compute(Real& arg1, Real& arg2);
  virtual Literal* Compute(Fraction& arg1, Fraction& arg2);
  virtual Literal* Compute(ExpressionLiteral& arg1, ExpressionLiteral& arg2);
  virtual Literal* Compute(Integer& arg1, Real& arg2);
  virtual Literal* Compute(Real& arg1, Integer& arg2);
  virtual Literal* Compute(Integer& arg1, Fraction& arg2);
  virtual Literal* Compute(Fraction& arg1, Integer& arg2);
  virtual Literal* Compute(Real& arg1, Fraction& arg2);
  virtual Literal* Compute(Fraction& arg1, Real& arg2);
  virtual Literal* Compute(Integer& arg1, ExpressionLiteral& arg2);
  virtual Literal* Compute(Real& arg1, ExpressionLiteral& arg2);
  virtual Literal* Compute(Fraction& arg1, ExpressionLiteral& arg2);
  virtual Literal* Compute(ExpressionLiteral& arg1, Integer& arg2);
  virtual Literal* Compute(ExpressionLiteral& arg1, Real& arg2);
  virtual Literal* Compute(ExpressionLiteral& arg1, Fraction& arg2);
};

#endif  // BINARY_OPERATOR_H