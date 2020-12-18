#ifndef COMPUTER_EXCEPTION_H_
#define COMPUTER_EXCEPTION_H_

#include <QString>

using namespace std;

class ComputerException {
  QString info_;

 public:
  ComputerException(const QString& info) : info_(info){};

  virtual ~ComputerException(){};

  QString GetInfo() const { return info_; }
};

#endif  // COMPUTER_EXCEPTION_H_
