#include "Program.h"

const string Program::Print() const {
  string result = "";
  for (Operand* element : elements_) {
    result += element->Print();
  }
  return result;
}