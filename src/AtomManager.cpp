#include "AtomManager.h"

AtomManager::~AtomManager() {
  for (Atom* atom : atoms_) delete atom;
}

AtomManager::AtomHandler AtomManager::atom_handler_;

Atom& AtomManager::AddAtom(QString const& id, Literal* literal) {
  for (Atom* atom : atoms_) {
    if (atom->GetId() == id) {
      atom->SetValue(literal);
      return *atom;
    }
  }
  atoms_.push_back(new Atom(id, literal));
  return *(atoms_.back());
}

bool AtomManager::CheckExistedAtom(QString const& id) {
  for (Atom* atom : atoms_) {
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

void AtomManager::FreeInstance() {
  delete atom_handler_.instance;
  atom_handler_.instance = nullptr;
}