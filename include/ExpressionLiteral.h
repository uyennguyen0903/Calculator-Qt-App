#ifndef EXPRESSION_LITERAL_H_
#define EXPRESSION_LITERAL_H_

#include "Atom.h"
#include "Literal.h"

using namespace std;

class ExpressionLiteral : public Literal {
 private:
  QString id_;

 public:
  ExpressionLiteral(QString const& id) : id_(id){};

  const QString Print() const override { return id_; }

  LiteralType GetLiteralType() const override {
    return LiteralType::kExpression;
  }
};

#endif  // EXPRESSION_LITERAL_H_