#ifndef ATOM_H_
#define ATOM_H_

#include <QString>

#include "Literal.h"
#include "NumericLiteral.h"
#include "Program.h"

using namespace std;

class Atom {
 private:
  QString id_;
  Literal* value_;

 public:
  Atom(QString const& id, Literal* literal) : id_(id), value_(literal){};

  ~Atom() { delete value_; }

  const QString GetId() const { return id_; }

  Literal* CopyAtomValue() const;

  void SetValue(Literal* literal);

  bool CheckEmptyAtom() const;
};

#endif  // ATOM_H_
