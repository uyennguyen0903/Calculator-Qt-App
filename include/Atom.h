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
  vector<Literal*> values_;
  // Save all the values associated to Atom for later back-up.

 public:
  Atom(QString const& id, Literal* literal) : id_(id) {
    if (literal != nullptr) values_.push_back(literal);
  };

  ~Atom() {
    for (Literal* value : values_) delete value;
  }

  const QString GetId() const { return id_; }

  Literal* CopyAtomValue();

  void SetValue(Literal* literal);

  void Restore();
};

#endif  // ATOM_H_