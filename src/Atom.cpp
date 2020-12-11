#include "Atom.h"

void Atom::SetValue(Literal* literal) {
  delete literal_;
  literal_ = literal;
}