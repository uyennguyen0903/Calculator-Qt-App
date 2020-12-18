#ifndef LITERAL_MANAGER_H_
#define LITERAL_MANAGER_H_

#include <vector>

#include "ExpressionLiteral.h"
#include "Literal.h"
#include "NumericLiteral.h"
#include "Program.h"

using namespace std;

class LiteralManager {
 private:
  vector<Literal*> literals_;

  LiteralManager() = default;

  ~LiteralManager();

  LiteralManager(const LiteralManager& lm) = delete;

  LiteralManager& operator=(const LiteralManager& lm) = delete;

  // Design Pattern Singleton.
  struct LiteralHandler {
    LiteralManager* instance;
    LiteralHandler() : instance(nullptr){};
    ~LiteralHandler() { delete instance; }
  };

  static LiteralHandler literal_handler_;

 public:
  Literal& AddLiteral(Literal* const literal);

  void RemoveLiteral(Literal& literal);

  static LiteralManager& GetInstance();

  static void LibererInstance();
};

#endif  // LITERAL_MANAGER_H_
