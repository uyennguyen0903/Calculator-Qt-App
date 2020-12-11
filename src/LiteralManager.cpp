#include "LiteralManager.h"

LiteralManager::~LiteralManager() {
  for (auto p : literals_) {
    delete p.first;
  }
}

Literal& LiteralManager::AddLiteral(Literal* const literal,
                                    const Literal::LiteralType& type) {
  literals_.push_back(make_pair(literal, type));
  return *(literals_.back().first);
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