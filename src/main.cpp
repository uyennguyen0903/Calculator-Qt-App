#include <QApplication>
#include <QString>
#include <iostream>
#include <sstream>

#include "Operator.h"
#include "QComputer.h"

using namespace std;

// int main(int argc, char* argv[]) {
//   QApplication app(argc, argv);
//   QComputer fenetre;
//   fenetre.setFixedSize(700, 600);
//   fenetre.show();
//   return app.exec();
// }

int main() {
  string ss;
  getline(cin, ss);

  QString expression = QString::fromStdString(ss);

  QStringList operand_list =
      expression.split(QRegExp("\\s+"), QString::SkipEmptyParts);

  for (int i = 0; i < operand_list.size(); ++i) {
    bool valid_program = true;
    if (operand_list.at(i) == "[") {
      // Do Something To Read Program. Maybe add a methode with QStringList arg
      // in class Prog. This methode should return true of false to inform.
      if (!valid_program) {
        
      }
    }

  }
  return 0;
}