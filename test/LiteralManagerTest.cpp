#include <QString>
#include <iostream>

#include "../include/Controller.h"
#include "../include/ExpressionLiteral.h"
#include "../include/Literal.h"
#include "../include/LiteralManager.h"
#include "../include/Pile.h"

int main() {
  Pile* pile = new Pile;
  Controller* controller = new Controller(LiteralManager::GetInstance(), *pile);
  LiteralManager& manager = LiteralManager::GetInstance();
  pile->Push(manager.AddLiteral(new Integer(5)));
  pile->Push(manager.AddLiteral(new Fraction(6 / 3)));
  pile->Push(manager.AddLiteral(new Real(0.999)));
  for (Pile::Iterator it = pile->begin(); it != pile->end(); ++it) {
    QString num = (*it).Print();
    cout << num.toLocal8Bit().constData() << endl;
  }
  return 0;
}