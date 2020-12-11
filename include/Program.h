#ifndef PROGRAM_H_
#define PROGRAM_H_

#include <vector>

#include "Literal.h"
#include "Operand.h"

using namespace std;

class Program : public Literal, public Operand {
 private:
  vector<Operand*> elements_;

 public:
  Program(vector<Operand*> elements) : elements_(elements) {}

  ~Program() {
    for (Operand* element : elements_) delete element;
  }

  const string Print() const;
};

#endif  // PROGRAM_H_