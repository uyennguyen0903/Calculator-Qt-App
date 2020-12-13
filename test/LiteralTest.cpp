#include <QString>
#include <iostream>

#include "../include/ExpressionLiteral.h"
#include "../include/Literal.h"
#include "../include/NumericLiteral.h"

using namespace std;

int main() {
  Literal* int1 = new Integer(5);
  cout << (int1->Print()).toLocal8Bit().constData() << endl;

  Literal* frac1 = new Fraction(2, 4);
  cout << (frac1->Print()).toLocal8Bit().constData() << endl;

  Literal* real1 = new Real(0.999);
  cout << (real1->Print()).toLocal8Bit().constData() << endl;

  return 0;
}