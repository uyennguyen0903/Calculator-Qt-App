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
  fenetre.setFixedWidth(680);
  fenetre.show();
  return app.exec();
}
