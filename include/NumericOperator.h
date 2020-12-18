#ifndef NUMERIC_OPERATOR_H_
#define NUMERIC_OPERATOR_H_

#include "AtomManager.h"
#include "BinaryOperator.h"
#include "ComputerException.h"
#include "NumericLiteral.h"
#include "Operator.h"
#include "Utils.h"

class NumericOperator : public BinaryOperator {
 public:
  NumericOperator(LiteralManager& literal_manager, Pile& pile)
      : BinaryOperator(literal_manager, pile){};

  virtual const QString Print() const = 0;

  void UpdatePile(Literal& arg1, Literal& arg2, Literal* res,
                  const QString& error_str) override;

  Literal* CastSameType(Literal& arg1, Literal& arg2);

  Literal* Compute(Literal& arg1, Literal& arg2) override;

  virtual Literal* Compute(Integer& arg1, Integer& arg2) = 0;
  virtual Literal* Compute(Real& arg1, Real& arg2) = 0;
  virtual Literal* Compute(Fraction& arg1, Fraction& arg2) = 0;
};

class AdditionOperator : public NumericOperator {
 private:
  QString expression_ = "+";

 public:
  AdditionOperator(LiteralManager& literal_manager, Pile& pile)
      : NumericOperator(literal_manager, pile){};

  const QString Print() const override { return expression_; }

  Literal* Compute(Integer& arg1, Integer& arg2) override;
  Literal* Compute(Real& arg1, Real& arg2) override;
  Literal* Compute(Fraction& arg1, Fraction& arg2) override;
};

class SubtractionOperator : public NumericOperator {
 private:
  QString expression_ = "-";

 public:
  SubtractionOperator(LiteralManager& literal_manager, Pile& pile)
      : NumericOperator(literal_manager, pile){};

  const QString Print() const override { return expression_; }

  Literal* Compute(Integer& arg1, Integer& arg2) override;
  Literal* Compute(Real& arg1, Real& arg2) override;
  Literal* Compute(Fraction& arg1, Fraction& arg2) override;
};

class MultiplyOperator : public NumericOperator {
 private:
  QString expression_ = "-";

 public:
  MultiplyOperator(LiteralManager& literal_manager, Pile& pile)
      : NumericOperator(literal_manager, pile){};

  const QString Print() const override { return expression_; }

  Literal* Compute(Integer& arg1, Integer& arg2) override;
  Literal* Compute(Real& arg1, Real& arg2) override;
  Literal* Compute(Fraction& arg1, Fraction& arg2) override;
};

class DivisionOperator : public NumericOperator {
 private:
  QString expression_ = "-";

 public:
  DivisionOperator(LiteralManager& literal_manager, Pile& pile)
      : NumericOperator(literal_manager, pile){};

  const QString Print() const override { return expression_; }

  Literal* Compute(Integer& arg1, Integer& arg2) override;
  Literal* Compute(Real& arg1, Real& arg2) override;
  Literal* Compute(Fraction& arg1, Fraction& arg2) override;
};

#endif  // NUMERIC_OPERATOR_H