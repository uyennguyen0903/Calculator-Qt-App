#ifndef LITERAL_H_
#define LITERAL_H_

#include <QString>

#include "Operand.h"

using namespace std;

class Literal : public Operand {
 public:
  enum LiteralType { kInteger = 0, kReal, kFraction, kProgram, kExpression };

  static constexpr LiteralType kLiteralList[] = {kInteger, kReal, kFraction,
                                                 kProgram, kExpression};

  Literal() = default;

  virtual ~Literal(){};

  virtual const QString Print() const = 0;

  virtual LiteralType GetLiteralType() const = 0;

  Literal& GetLiteral() { return *this; }
};

#endif  // LITERAL_H_