#ifndef ATOM_H_
#define ATOM_H_

#include <QString>

#include "Literal.h"
#include "NumericLiteral.h"

using namespace std;

class Atom {
 private:
  QString id_;
  Literal* literal_ = nullptr;

 public:
  Atom(QString const& id, Literal* literal) : id_(id), literal_(literal){};

  ~Atom() { delete literal_; }

  const QString GetId() const { return id_; }

  Literal* CopyAtomValue();

  void SetValue(Literal* literal);
};

#endif  // ATOM_H_
