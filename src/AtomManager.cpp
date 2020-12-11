#include "AtomManager.h"

AtomManager::AtomHandler AtomManager::atom_handler_;

Atom& AtomManager::AddAtom(string const& id, Literal* literal,
                           const Literal::LiteralType& type) {
  for (Atom* atom : atoms) {
    if (atom->GetId() == id) {
      atom->SetValue(literal, type);
      return *atom;
    }
  }
  atoms.push_back(new Atom(id, literal, type));
  return *(atoms.back());
}

bool AtomManager::CheckExistedAtom(string const& id) {
  for (Atom* atom : atoms) {
    if (atom->GetId() == id) {
      return true;
    }
  }
  return false;
}

AtomManager& AtomManager::GetInstance() {
  if (atom_handler_.instance == nullptr) {
    atom_handler_.instance = new AtomManager;
  }
  return *(atom_handler_.instance);
}

void AtomManager::LibererInstance() {
  delete atom_handler_.instance;
  atom_handler_.instance = nullptr;
}