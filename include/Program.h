#ifndef PROGRAM_H_
#define PROGRAM_H_

#include <QString>
#include <vector>

#include "AtomManager.h"
#include "Literal.h"
#include "Operand.h"

using namespace std;

class Program : public Literal {
 private:
  vector<QString> elements_;

 public:
  Program(vector<QString> elements) : elements_(elements){};

  ~Program() = default;

  vector<QString> GetProgramElement() const { return elements_; }

  Program(const Program& prog) : elements_(prog.GetProgramElement()){};

  const QString Print() const override;

  LiteralType GetLiteralType() const override { return LiteralType::kProgram; }
};

#endif  // PROGRAM_H_