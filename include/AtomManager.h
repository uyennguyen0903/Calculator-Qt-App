#ifndef ATOM_MANAGER_H_
#define ATOM_MANAGER_H_

#include <QString>
#include <vector>

#include "Atom.h"
#include "NumericLiteral.h"
#include "Program.h"

using namespace std;

class AtomManager {
 private:
  vector<Atom*> atoms_;

  ~AtomManager();

  AtomManager() = default;

  AtomManager(const AtomManager& atom_mananger) = delete;

  AtomManager& operator=(const AtomManager& atom_manager) = delete;

  // Design Pattern Singleton.
  struct AtomHandler {
    AtomManager* instance;
    AtomHandler() : instance(nullptr){};
    ~AtomHandler() { delete instance; }
  };

  static AtomHandler atom_handler_;

 public:
  Atom& AddAtom(const QString& id, Literal* const literal);

  bool CheckExistedAtom(const QString& id);

  Literal* EvalAtom(const QString& id);

  Atom& GetAtom(const QString& id);

  void SetValueAtom(const QString& id, Literal* const literal);

  static AtomManager& GetInstance();

  static void FreeInstance();
};

#endif  // ATOM_MANAGER_H_