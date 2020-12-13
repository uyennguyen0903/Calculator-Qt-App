#include <QString>
#include <iostream>

#include "../include/Operand.h"
#include "../include/Utils.h"

using namespace std;

int main() {
  QStringList str_list = {"DUP",    "<",      "-123", ".234", "0.0", "123.",
                          "1.5",    "1,5",    "4/55", "//",   "4/",  "/5",
                          "ABS",    "1A",     "afd",  "\"",   "\'",  "\'\'",
                          "\'re\'", "\'A4\'", "\'4\'"};

  for (int i = 0; i < str_list.size(); ++i) {
    cout << str_list[i].toLocal8Bit().constData() << " ";
    Operand::OperandType type = FindTypeOperand(str_list[i]);
    if (type == Operand::OperandType::kAtom) cout << "kAtom";
    if (type == Operand::OperandType::kExpression) cout << "kExpression";
    if (type == Operand::OperandType::kFraction) cout << "kFraction";
    if (type == Operand::OperandType::kInteger) cout << "kInteger";
    if (type == Operand::OperandType::kOperator) cout << "kOperator";
    if (type == Operand::OperandType::kProgram) cout << "kProgram";
    if (type == Operand::OperandType::kReal) cout << "kReal";
    if (type == Operand::OperandType::kUndefined) cout << "kUndefined";
    cout << endl;
  }
}
