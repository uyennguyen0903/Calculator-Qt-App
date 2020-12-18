#ifndef ATOM_MANAGER_H_
#define ATOM_MANAGER_H_

#include <QString>
#include <iostream>
#include <vector>

#include "Atom.h"

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

  vector<pair<QString, Literal*>> SaveStatus() const;

  void Restore(const vector<pair<QString, Literal*>>& atoms);
};

#endif  // ATOM_MANAGER_H_