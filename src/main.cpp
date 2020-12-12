#include <QApplication>
#include <iostream>

#include "QComputer.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  QComputer fenetre;
  fenetre.setFixedSize(700, 600);
  fenetre.show();
  return app.exec();
}
