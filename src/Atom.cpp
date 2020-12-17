#include "Atom.h"

void Atom::SetValue(Literal* literal) {
  if (literal != nullptr) values_.push_back(literal);
}

Literal* Atom::CopyAtomValue() {
  if (values_.empty()) return nullptr;
  Literal* value = values_.back();
  if (value->GetLiteralType() == Literal::LiteralType::kInteger) {
    return new Integer(dynamic_cast<Integer*>(value));
  }
  if (value->GetLiteralType() == Literal::LiteralType::kFraction) {
    return new Fraction(dynamic_cast<Fraction*>(value));
  }
  if (value->GetLiteralType() == Literal::LiteralType::kReal) {
    return new Real(dynamic_cast<Real*>(value));
  }
  if (value->GetLiteralType() == Literal::LiteralType::kProgram) {
    return new Program(dynamic_cast<Program*>(value));
  }
  return nullptr;
}

void Atom::Restore() {
  if (values_.empty()) return;
  values_.pop_back();
}

bool Atom::CheckEmptyAtom() const {
  if (values_.empty())
    return true;
  else
    return false;
}