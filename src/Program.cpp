#include "Program.h"

Program::~Program() {
  for (Operand* element : elements_) delete element;
}

const string Program::Print() const {
  string result = "";
  for (Operand* element : elements_) {
    result += element->Print();
  }
  return result;
}