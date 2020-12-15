#include "LiteralManager.h"

#include <iostream>

LiteralManager::~LiteralManager() {
  for (auto literal : literals_) {
    delete literal;
  }
}

Literal& LiteralManager::AddLiteral(Literal* const literal) {
  literals_.push_back(literal);
  return *(literals_.back());
}

void LiteralManager::RemoveLiteral(Literal& literal) {
  for (size_t i = 0; i < literals_.size(); ++i) {
    if (literals_[i] == &literal) {
      delete literals_[i];
      literals_.erase(literals_.begin() + i);
      return;
    }
  }
}

LiteralManager::LiteralHandler LiteralManager::literal_handler_;

LiteralManager& LiteralManager::GetInstance() {
  if (literal_handler_.instance == nullptr) {
    literal_handler_.instance = new LiteralManager;
  }
  return *(literal_handler_.instance);
}

void LiteralManager::LibererInstance() {
  delete literal_handler_.instance;
  literal_handler_.instance = nullptr;
}
