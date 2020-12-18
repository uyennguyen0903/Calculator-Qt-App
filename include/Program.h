#ifndef PROGRAM_H_
#define PROGRAM_H_

#include <QString>
#include <vector>

#include "Literal.h"
#include "Operand.h"

using namespace std;

class Program : public Literal {
 private:
  QString program_str_;

 public:
  Program(QString program_str) : program_str_(program_str){};

  ~Program() = default;

  QString GetProgramStr() const { return program_str_; }

  Program(Program* const prog) : program_str_(prog->GetProgramStr()){};

  const QString Print() const override { return program_str_; };

  LiteralType GetLiteralType() const override { return LiteralType::kProgram; }
};

#endif  // PROGRAM_H_
