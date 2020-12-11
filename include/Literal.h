#ifndef LITERAL_H_
#define LITERAL_H_

#include <iostream>

using namespace std;

class Literal {
 public:
  enum LiteralType { kInteger = 0, kReal, kFraction, kProgram, kExpression };
  static constexpr LiteralType kLiteralList[] = {kInteger, kReal, kFraction,
                                                 kProgram, kExpression};
  virtual ~Literal(){};
  virtual const string Print() const = 0;
};

#endif  // LITERAL_H_