#include <QApplication>
#include <QString>
#include <iostream>
#include <sstream>

#include "Operator.h"
#include "QComputer.h"

using namespace std;

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  QComputer fenetre;
  fenetre.setFixedSize(700, 750);
  fenetre.show();
  return app.exec();
}
