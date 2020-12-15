#ifndef EXPRESSION_LITERAL_H_
#define EXPRESSION_LITERAL_H_

#include "Atom.h"
#include "Literal.h"

using namespace std;

class ExpressionLiteral : public Literal {
 private:
  QString id_;
  Atom* atom_;

 public:
  ExpressionLiteral(QString const& id, Atom& atom) : id_(id), atom_(&atom){};

  const QString Print() const override { return id_; }

  Atom& GetAtom() const { return *atom_; }

  ~ExpressionLiteral() { atom_ = nullptr; }

  LiteralType GetLiteralType() const override {
    return LiteralType::kExpression;
  }
};

#endif  // EXPRESSION_LITERAL_H_