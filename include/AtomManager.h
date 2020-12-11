#ifndef ATOM_MANAGER_H_
#define ATOM_MANAGER_H_

#include <vector>

#include "Atom.h"

using namespace std;

class AtomManager {
 private:
  vector<Atom*> atoms;

  ~AtomManager() {
    for (Atom* atom : atoms) delete atom;
  }

  AtomManager() = default;

  AtomManager(const AtomManager& am) = delete;

  AtomManager& operator=(const AtomManager& am) = delete;

  struct AtomHandler {
    AtomManager* instance;
    AtomHandler() : instance(nullptr) {}
    ~AtomHandler() { delete instance; }
  };

  static AtomHandler atom_handler_;

 public:
  Atom& AddAtom(string const& id, Literal* literal,
                const Literal::LiteralType& type);
  bool CheckExistedAtom(string const& id);
  static AtomManager& GetInstance();
  static void LibererInstance();
};

#endif  // ATOM_MANAGER_H_