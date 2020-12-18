#include "AtomManager.h"

#include <iostream>

AtomManager::~AtomManager() {
  for (Atom* atom : atoms_) delete atom;
}

AtomManager::AtomHandler AtomManager::atom_handler_;

Atom& AtomManager::AddAtom(const QString& id, Literal* const literal) {
  for (Atom* atom : atoms_) {
    if (atom->GetId() == id) {
      atom->SetValue(literal);
      return *atom;
    }
  }
  atoms_.push_back(new Atom(id, literal));
  return *(atoms_.back());
}

bool AtomManager::CheckExistedAtom(const QString& id) {
  for (Atom* atom : atoms_) {
    if (atom->GetId() == id && atom->CopyAtomValue() != nullptr) {
      return true;
    }
  }
  return false;
}

Literal* AtomManager::EvalAtom(const QString& id) {
  for (Atom* atom : atoms_) {
    if (atom->GetId() == id) {
      return atom->CopyAtomValue();
    }
  }

  return nullptr;
}

Atom& AtomManager::GetAtom(const QString& id) {
  for (Atom* atom : atoms_) {
    if (atom->GetId() == id) {
      return *atom;
    }
  }
  return AddAtom(id, nullptr);
}

void AtomManager::SetValueAtom(const QString& id, Literal* const literal) {
  for (Atom* atom : atoms_) {
    if (atom->GetId() == id) {
      atom->SetValue(literal);
      return;
    }
  }
}

void AtomManager::Restore(const vector<pair<QString, Literal*>>& backup_data) {
  for (auto p : backup_data) {
    SetValueAtom(p.first, p.second);
  }
}

vector<pair<QString, Literal*>> AtomManager::SaveStatus() const {
  vector<pair<QString, Literal*>> backup_data;
  for (Atom* atom : atoms_) {
    backup_data.push_back(make_pair(atom->GetId(), atom->CopyAtomValue()));
  }
  return backup_data;
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
