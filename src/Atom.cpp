#include "Atom.h"

#include <iostream>

void Atom::SetValue(Literal* literal) {
  delete value_;
  value_ = literal;
}

Literal* Atom::CopyAtomValue() const {
  if (value_ == nullptr) return nullptr;
  if (value_->GetLiteralType() == Literal::LiteralType::kInteger) {
    return new Integer(dynamic_cast<Integer*>(value_));
  }
  if (value_->GetLiteralType() == Literal::LiteralType::kFraction) {
    return new Fraction(dynamic_cast<Fraction*>(value_));
  }
  if (value_->GetLiteralType() == Literal::LiteralType::kReal) {
    return new Real(dynamic_cast<Real*>(value_));
  }
  if (value_->GetLiteralType() == Literal::LiteralType::kProgram) {
    return new Program(dynamic_cast<Program*>(value_));
  }
  return nullptr;
}

bool Atom::CheckEmptyAtom() const {
  if (value_ == nullptr)
    return true;
  else
    return false;
}
