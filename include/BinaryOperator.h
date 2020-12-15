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

  void Execute();

  Literal* CastLiteral(Literal& arg1, Literal& arg2);

  virtual const QString Print() const = 0;

  virtual Literal* Compute(const Integer& arg1, const Integer& arg2);
  virtual Literal* Compute(const Real& arg1, const Real& arg2);
  virtual Literal* Compute(const Fraction& arg1, const Fraction& arg2);
  virtual Literal* Compute(const Integer& arg1, const Real& arg2);
  virtual Literal* Compute(const Real& arg1, const Integer& arg2);
  virtual Literal* Compute(const Integer& arg1, const Fraction& arg2);
  virtual Literal* Compute(const Fraction& arg1, const Integer& arg2);
  virtual Literal* Compute(const Real& arg1, const Fraction& arg2);
  virtual Literal* Compute(const Fraction& arg1, const Real& arg2);
  virtual Literal* Compute(const Integer& arg1, const ExpressionLiteral& arg2);
  virtual Literal* Compute(const Real& arg1, const ExpressionLiteral& arg2);
  virtual Literal* Compute(const Fraction& arg1, const ExpressionLiteral& arg2);
  virtual Literal* Compute(const ExpressionLiteral& arg1, const Integer& arg2);
  virtual Literal* Compute(const ExpressionLiteral& arg1, const Real& arg2);
  virtual Literal* Compute(const ExpressionLiteral& arg1, const Fraction& arg2);
  virtual Literal* Compute(const ExpressionLiteral& arg1,
                           const ExpressionLiteral& arg2);
};

#endif  // BINARY_OPERATOR_H