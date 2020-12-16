#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <iostream>
#include <vector>

#include "Atom.h"
#include "AtomManager.h"
#include "BinaryOperator.h"
#include "ExpressionLiteral.h"
#include "HandlingOperator.h"
#include "LiteralManager.h"
#include "NumericLiteral.h"
#include "NumericOperator.h"
#include "Operand.h"
#include "Operator.h"
#include "Pile.h"
#include "Program.h"
#include "Utils.h"

// TODO 1: Throw all the errors to ComputerException to clean code instead of
// using pile_SetMessge().

// TODO 2: The program literal is now just used to read command line, needs to
// be implemented later.

class Controller {
 private:
  LiteralManager& literal_manager_;
  AtomManager& atom_manager_ = AtomManager::GetInstance();
  Pile& pile_;
  Operator* operator_;
  QString command_error_;

 public:
  Controller(LiteralManager& literal_manager, Pile& pile,
             Operator* op = nullptr)
      : literal_manager_(literal_manager),
        pile_(pile),
        operator_(op),
        command_error_(""){};

  ~Controller() { delete operator_; }

  void SetOperator(Operator* op);

  void Commande(const QString& expression);

  void ExecuteOperator(const QString& op);

  void EvalExpressionOrProgram();

  int ParseProgram(const QStringList& list, int position);

  void ClearError() { command_error_ = ""; }

  QString GetErrorCommand() const { return command_error_; }
};

#endif  // CONTROLLER_H_