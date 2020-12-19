#ifndef UNARY_OPERATOR_H_
#define UNARY_OPERATOR_H_

#include "AtomManager.h"
#include "ComputerException.h"
#include "NumericLiteral.h"
#include "Operator.h"
#include "Program.h"
#include "Utils.h"

class UnaryOperator : public Operator {
 public:
  UnaryOperator(LiteralManager& literal_manager, Pile& pile)
      : Operator(literal_manager, pile){};

  virtual ~UnaryOperator(){};

  void Execute() override;

  virtual const QString Print() const = 0;

  virtual Literal* Compute(Literal& arg) = 0;
};

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

class Not : public UnaryOperator {
 private:
  QString expression_ = "NOT";

 public:
  Not(LiteralManager& literal_manager, Pile& pile)
      : UnaryOperator(literal_manager, pile){};

  const QString Print() const override { return expression_; };

  Literal* Compute(Literal& arg) override;
};

class NumDen : public UnaryOperator {
 private:
  QString expression_ = "";
  bool num_;  // True on getting numerator, false otherwise.

 public:
  NumDen(LiteralManager& literal_manager, Pile& pile, bool num)
      : UnaryOperator(literal_manager, pile), num_(num){};

  const QString Print() const override { return expression_; };

  Literal* Compute(Literal& arg) override;

  Literal* Compute(Integer& arg);
  Literal* Compute(Fraction& arg);
  Literal* Compute(ExpressionLiteral& arg);
};

#endif  // UNARY_OPERATOR_H
