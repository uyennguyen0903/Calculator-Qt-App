#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "LiteralManager.h"
#include "Operator.h"
#include "Pile.h"

class Controller {
 private:
  LiteralManager& literal_manager_;
  Pile& pile_;
  Operator* operator_;

 public:
  Controller(LiteralManager& literal_manager, Pile& pile,
             Operator* op = nullptr)
      : literal_manager_(literal_manager), pile_(pile), operator_(op){};

  ~Controller() { delete operator_; }

  void SetOperator(Operator* op);

  void Commande(const QString& expression);
};

#endif  // CONTROLLER_H_