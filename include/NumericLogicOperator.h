#ifndef NUMERIC_LOGIC_OPERATOR_H_
#define NUMERIC_LOGIC_OPERATOR_H_

#include "AtomManager.h"
#include "BinaryOperator.h"
#include "ComputerException.h"
#include "NumericLiteral.h"
#include "Operator.h"
#include "Utils.h"

class NumericLogicOperator : public BinaryOperator {
 public:
  NumericLogicOperator(LiteralManager& literal_manager, Pile& pile)
      : BinaryOperator(literal_manager, pile){};

  virtual const QString Print() const = 0;

  Literal* CastSameType(Literal& arg1, Literal& arg2);

  Literal* Compute(Literal& arg1, Literal& arg2) override;

  virtual Literal* Compute(Integer& arg1, Integer& arg2) = 0;
  virtual Literal* Compute(Real& arg1, Real& arg2) = 0;
  virtual Literal* Compute(Fraction& arg1, Fraction& arg2) = 0;
};

class AdditionOperator : public NumericLogicOperator {
 private:
  QString expression_ = "+";

 public:
  AdditionOperator(LiteralManager& literal_manager, Pile& pile)
      : NumericLogicOperator(literal_manager, pile){};

  const QString Print() const override { return expression_; }

  Literal* Compute(Integer& arg1, Integer& arg2) override;
  Literal* Compute(Real& arg1, Real& arg2) override;
  Literal* Compute(Fraction& arg1, Fraction& arg2) override;
};

class SubtractionOperator : public NumericLogicOperator {
 private:
  QString expression_ = "-";

 public:
  SubtractionOperator(LiteralManager& literal_manager, Pile& pile)
      : NumericLogicOperator(literal_manager, pile){};

  const QString Print() const override { return expression_; }

  Literal* Compute(Integer& arg1, Integer& arg2) override;
  Literal* Compute(Real& arg1, Real& arg2) override;
  Literal* Compute(Fraction& arg1, Fraction& arg2) override;
};

class MultiplyOperator : public NumericLogicOperator {
 private:
  QString expression_ = "*";

 public:
  MultiplyOperator(LiteralManager& literal_manager, Pile& pile)
      : NumericLogicOperator(literal_manager, pile){};

  const QString Print() const override { return expression_; }

  Literal* Compute(Integer& arg1, Integer& arg2) override;
  Literal* Compute(Real& arg1, Real& arg2) override;
  Literal* Compute(Fraction& arg1, Fraction& arg2) override;
};

class DivisionOperator : public NumericLogicOperator {
 private:
  QString expression_ = "/";

 public:
  DivisionOperator(LiteralManager& literal_manager, Pile& pile)
      : NumericLogicOperator(literal_manager, pile){};

  const QString Print() const override { return expression_; }

  Literal* Compute(Integer& arg1, Integer& arg2) override;
  Literal* Compute(Real& arg1, Real& arg2) override;
  Literal* Compute(Fraction& arg1, Fraction& arg2) override;
};

class Greater : public NumericLogicOperator {
 private:
  QString expression_ = "";
  bool inverse_;  // True on 'left < right', False on 'left > right'.
  bool equal_;    // True on 'greater or equal (>=)', False on 'strictly greater
                  // (>)'.

 public:
  Greater(LiteralManager& literal_manager, Pile& pile, bool inverse, bool equal)
      : NumericLogicOperator(literal_manager, pile),
        inverse_(inverse),
        equal_(equal){};

  const QString Print() const override { return expression_; }

  Literal* Compute(Integer& arg1, Integer& arg2) override;
  Literal* Compute(Real& arg1, Real& arg2) override;
  Literal* Compute(Fraction& arg1, Fraction& arg2) override;
};

class Equal : public NumericLogicOperator {
 private:
  QString expression_ = "=";
  bool diff_;  // True on '!=', False on '='.

 public:
  Equal(LiteralManager& literal_manager, Pile& pile, bool diff)
      : NumericLogicOperator(literal_manager, pile), diff_(diff){};

  const QString Print() const override { return expression_; }

  Literal* Compute(Integer& arg1, Integer& arg2) override;
  Literal* Compute(Real& arg1, Real& arg2) override;
  Literal* Compute(Fraction& arg1, Fraction& arg2) override;
};

#endif  // NUMERIC_LOGIC_OPERATOR_H