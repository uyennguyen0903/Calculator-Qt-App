#ifndef OPERATOR_H_
#define OPERATOR_H_

#include <set>

#include "Literal.h"
#include "NumericLiteral.h"
#include "Operand.h"
#include "Pile.h"

using namespace std;

class Operator : public Operand {
 protected:
  LiteralManager& literal_manager_;
  Pile& pile_;

  bool IsEnoughArguments(size_t n) const;

 public:
  Operator(LiteralManager& literal_manager, Pile& pile)
      : literal_manager_(literal_manager), pile_(pile){};

  virtual ~Operator(){};

  static const set<QString> kOperatorList;

  void Execute();

  Literal* CastLiteral(Literal& arg1, Literal& arg2);

  virtual const QString Print() const = 0;

  virtual Literal* Compute(const Integer& arg1, const Integer& arg2) = 0;
  virtual Literal* Compute(const Real& arg1, const Real& arg2) = 0;
  virtual Literal* Compute(const Fraction& arg1, const Fraction& arg2) = 0;
  virtual Literal* Compute(const Integer& arg1, const Real& arg2) = 0;
  virtual Literal* Compute(const Real& arg1, const Integer& arg2) = 0;
  virtual Literal* Compute(const Integer& arg1, const Fraction& arg2) = 0;
  virtual Literal* Compute(const Fraction& arg1, const Integer& arg2) = 0;
  virtual Literal* Compute(const Real& arg1, const Fraction& arg2) = 0;
  virtual Literal* Compute(const Fraction& arg1, const Real& arg2) = 0;
};

class AdditionOperator : public Operator {
 private:
  QString expression_ = "+";

 public:
  AdditionOperator(LiteralManager& literal_manager, Pile& pile)
      : Operator(literal_manager, pile){};

  const QString Print() const override { return expression_; }

  Literal* Compute(const Integer& arg1, const Integer& arg2) override;
  Literal* Compute(const Real& arg1, const Real& arg2) override;
  Literal* Compute(const Fraction& arg1, const Fraction& arg2) override;
  Literal* Compute(const Integer& arg1, const Real& arg2) override;
  Literal* Compute(const Real& arg1, const Integer& arg2) override;
  Literal* Compute(const Integer& arg1, const Fraction& arg2) override;
  Literal* Compute(const Fraction& arg1, const Integer& arg2) override;
  Literal* Compute(const Real& arg1, const Fraction& arg2) override;
  Literal* Compute(const Fraction& arg1, const Real& arg2) override;
};

#endif  // OPERATOR_H_