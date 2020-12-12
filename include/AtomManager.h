#ifndef ATOM_MANAGER_H_
#define ATOM_MANAGER_H_

#include <QString>
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
  Atom& AddAtom(QString const& id, Literal* literal);

  bool CheckExistedAtom(QString const& id);

  static AtomManager& GetInstance();

  static void FreeInstance();
};

#endif  // ATOM_MANAGER_H_