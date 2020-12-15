#include "Program.h"

const QString Program::Print() const {
  QString result = "[";
  for (QString element : elements_) {
    result.append(" " + element);
  }
  result.append(" ]");
  return result;
}