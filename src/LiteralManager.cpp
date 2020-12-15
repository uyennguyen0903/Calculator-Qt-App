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
      std::cout << literals_.size() << endl;
      std::cout << literals_[i]->Print().toLocal8Bit().constData() << endl;
      delete literals_[i];
      std::cout << literals_.size() << endl;
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

//   switch (type) {
//     case Literal::LiteralType::kInteger:
//       literals_.push_back(make_pair(dynamic_cast<Integer*>(literal),
//       type)); break;
//     case Literal::LiteralType::kReal:
//       literals_.push_back(make_pair(dynamic_cast<Real*>(literal), type));
//       break;
//     case Literal::LiteralType::kFraction:
//       literals_.push_back(make_pair(dynamic_cast<Fraction*>(literal),
//       type)); break;
//     case Literal::LiteralType::kProgram:
//       literals_.push_back(make_pair(dynamic_cast<Program*>(literal),
//       type)); break;
//     case Literal::LiteralType::kExpression:
//       literals_.push_back(
//           make_pair(dynamic_cast<ExpressionLiteral*>(literal), type));
//       break;
//   }