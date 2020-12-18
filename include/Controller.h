#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <iostream>
#include <vector>

#include "Atom.h"
#include "AtomManager.h"
#include "BinaryOperator.h"
#include "ExpressionLiteral.h"
#include "LiteralManager.h"
#include "NumericLiteral.h"
#include "NumericLogicOperator.h"
#include "Operand.h"
#include "Operator.h"
#include "Pile.h"
#include "PileCareTaker.h"
#include "Program.h"
#include "UnaryOperator.h"
#include "Utils.h"
#include "math.h"

class Controller {
 private:
  LiteralManager& literal_manager_;
  AtomManager& atom_manager_ = AtomManager::GetInstance();
  Pile& pile_;
  Operator* operator_;
  PileCareTaker* pile_care_taker_;

 public:
  Controller(LiteralManager& literal_manager, Pile& pile,
             Operator* op = nullptr)
      : literal_manager_(literal_manager),
        pile_(pile),
        operator_(op),
        pile_care_taker_(new PileCareTaker(&pile)){};

  ~Controller() {
    delete operator_;
    delete pile_care_taker_;
  }

  void SetOperator(Operator* op);

  void CommandeProcess(const QString& command);

  void ExecuteOperator(const QString& op);

  void PileBackUp() { pile_care_taker_->BackUp(); }

  void PileRestore() { pile_care_taker_->Undo(); }

  int ParseProgram(const QStringList& list, int position);

  void EVAL();

  void DUP();

  void DROP();

  void SWAP();

  void CLEAR();

  void FORGET();

  void IFT();
};

#endif  // CONTROLLER_H_
