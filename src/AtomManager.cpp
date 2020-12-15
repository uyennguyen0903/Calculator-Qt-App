#include "AtomManager.h"

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
    if (atom->GetId() == id) {
      return true;
    }
  }
  return false;
}

Literal* AtomManager::EvalAtom(const QString& id) {
  Literal* atom_value = nullptr;
  for (Atom* atom : atoms_) {
    if (atom->GetId() == id) {
      atom_value = atom->GetAtomValue();
      break;
    }
  }
  if (atom_value != nullptr) {
    if (atom_value->GetLiteralType() == Literal::LiteralType::kInteger) {
      return new Integer(dynamic_cast<Integer*>(atom_value));
    }
    if (atom_value->GetLiteralType() == Literal::LiteralType::kFraction) {
      return new Fraction(dynamic_cast<Fraction*>(atom_value));
    }
    if (atom_value->GetLiteralType() == Literal::LiteralType::kReal) {
      return new Real(dynamic_cast<Real*>(atom_value));
    }
  }
  throw(ComputerException("Atome n'est associée à aucune valeur."));
}

Atom& AtomManager::GetAtom(const QString& id) {
  for (Atom* atom : atoms_) {
    if (atom->GetId() == id) {
      return *atom;
    }
  }
  throw(ComputerException("ID n'existe pas."));
}

void AtomManager::SetValueAtom(const QString& id, Literal* const literal) {
  for (Atom* atom : atoms_) {
    if (atom->GetId() == id) {
      atom->SetValue(literal);
      return;
    }
  }
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