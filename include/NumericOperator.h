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

  Literal* Compute(const Integer& arg1, const Integer& arg2) override;
  Literal* Compute(const Real& arg1, const Real& arg2) override;
  Literal* Compute(const Fraction& arg1, const Fraction& arg2) override;
  Literal* Compute(const Integer& arg1, const Real& arg2) override;
  Literal* Compute(const Real& arg1, const Integer& arg2) override;
  Literal* Compute(const Integer& arg1, const Fraction& arg2) override;
  Literal* Compute(const Fraction& arg1, const Integer& arg2) override;
  Literal* Compute(const Real& arg1, const Fraction& arg2) override;
  Literal* Compute(const Fraction& arg1, const Real& arg2) override;
  // TODO : Implement Compute() method for 'Atom' & 'Program'.
};

class STO : public BinaryOperator {
 private:
  QString expression_ = "STO";
  AtomManager& atom_manager_ = AtomManager::GetInstance();

 public:
  STO(LiteralManager& literal_manager, Pile& pile)
      : BinaryOperator(literal_manager, pile){};

  const QString Print() const override { return expression_; }

  Literal* Compute(const Integer& arg1, const ExpressionLiteral& arg2) override;
  Literal* Compute(const Real& arg1, const ExpressionLiteral& arg2) override;
  Literal* Compute(const Fraction& arg1,
                   const ExpressionLiteral& arg2) override;
  // TODO :  Implement Compute() method for 'Program'.
};

#endif  // NUMERIC_OPERATOR_H