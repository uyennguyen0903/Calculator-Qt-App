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
  // vector<Operand*> elements_;
  vector<QString> elements_;
  AtomManager& atom_mananer_ = AtomManager::GetInstance();

 public:
  Program(vector<QString> elements) : elements_(elements){};

  ~Program();

  const QString Print() const;

  LiteralType GetLiteralType() const override { return LiteralType::kProgram; }
};

#endif  // PROGRAM_H_