#include "Controller.h"

void Controller::SetOperator(Operator* op) {
  delete operator_;
  operator_ = op;
}

void Controller::Commande(const QString& expression) {}