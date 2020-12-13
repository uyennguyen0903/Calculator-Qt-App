#include "Program.h"

// Program::Program(vector<QString> elements) {}

// Program::~Program() {
//   for (Operand* element : elements_) delete element;
// }

// const QString Program::Print() const {
//   QString result = "";
//   for (Operand* element : elements_) {
//     result += element->Print();
//   }
//   return result;
// }

const QString Program::Print() const {
  QString result = "";
  for (QString element : elements_) {
    result.append(element);
  }
  return result;
}