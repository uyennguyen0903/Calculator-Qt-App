#include "Atom.h"

void Atom::SetValue(Literal* literal) {
  delete literal_;
  literal_ = literal;
}

Literal* Atom::CopyAtomValue() {
  if (literal_ == nullptr) return nullptr;
  if (literal_->GetLiteralType() == Literal::LiteralType::kInteger) {
    return new Integer(dynamic_cast<Integer*>(literal_));
  }
  if (literal_->GetLiteralType() == Literal::LiteralType::kFraction) {
    return new Fraction(dynamic_cast<Fraction*>(literal_));
  }
  if (literal_->GetLiteralType() == Literal::LiteralType::kReal) {
    return new Real(dynamic_cast<Real*>(literal_));
  }
  return nullptr;
}