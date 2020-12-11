#ifndef EXPRESSION_LITERAL_H_
#define EXPRESSION_LITERAL_H_

#include <iostream>

#include "Literal.h"

using namespace std;

class ExpressionLiteral : public Literal {
 private:
  string id_;

 public:
 public:
  ExpressionLiteral(string const& id) : id_(id) {}
  const string Print() const override { return id_; }
};

#endif  // EXPRESSION_LITERAL_H_