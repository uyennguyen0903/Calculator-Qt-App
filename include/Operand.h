#ifndef OPERAND_H_
#define OPERAND_H_

#include <iostream>

using namespace std;

class Operand {
 public:
  enum OperandType {
    kInteger = 0,
    kReal,
    kFraction,
    kProgram,
    kExpression,
    kOperator
  };

  static constexpr OperandType kOperandList[] = {
      kInteger, kReal, kFraction, kProgram, kExpression, kOperator};

  Operand() = default;

  virtual ~Operand(){};

  virtual const string Print() const = 0;
};

#endif  // OPERAND_H_