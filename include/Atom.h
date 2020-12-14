#ifndef ATOM_H_
#define ATOM_H_

#include <QString>

#include "Literal.h"
#include "NumericLiteral.h"

using namespace std;

class Atom {
 private:
  QString id_;
  Literal* literal_ = nullptr;

 public:
  Atom(QString const& id, Literal* literal) : id_(id), literal_(literal){};

  ~Atom() { delete literal_; }

  const QString GetId() const { return id_; }

  Literal* GetAtomValue() const { return literal_; }

  void SetValue(Literal* literal);
};

#endif  // ATOM_H_

// Atom(string const& id, int int_value)
//     : id_(id), literal_type_(Literal::LiteralType::kInteger) {
//   numeric_literal_ = new Integer(int_value);
// }

// Atom(string const& id, double real_value)
//     : id_(id), literal_type_(Literal::LiteralType::kReal) {
//   numeric_literal_ = new Real(real_value);
// }

// Atom(string const& id, int numerator, int denominator)
//     : id_(id), literal_type_(Literal::LiteralType::kFraction) {
//   numeric_literal_ = new Fraction(numerator, denominator);
// }

// void SetValue(int int_value) {
//   delete numeric_literal_;
//   numeric_literal_ = new Integer(int_value);
// }

// void SetValue(double real_value) {
//   delete numeric_literal_;
//   numeric_literal_ = new Real(real_value);
// }

// void SetValue(int numerator, int denominator) {
//   delete numeric_literal_;
//   numeric_literal_ = new Fraction(numerator, denominator);
// }

// string GetExpressionLiteral() const { return "'" + id_ + "'"; }

// string Print() const { return numeric_literal_->Print(); }