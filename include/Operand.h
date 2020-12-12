#ifndef OPERAND_H_
#define OPERAND_H_

#include <QString>

using namespace std;

class Operand {
 public:
  enum OperandType {
    kInteger = 0,
    kReal,
    kFraction,
    kProgram,
    kExpression,
    kAtom,
    kOperator,
    kUndefined
  };

  static constexpr OperandType kOperandList[] = {
      kInteger, kReal, kFraction, kProgram, kExpression, kOperator, kUndefined, kAtom};

  Operand() = default;

  virtual ~Operand(){};

  virtual const QString Print() const = 0;
};

#endif  // OPERAND_H_