#ifndef COMPUTER_EXCEPTION_H_
#define COMPUTER_EXCEPTION_H_

#include <QString>
#include <stdexcept>

using namespace std;

class ComputerException : public exception {
  QString info_;

 public:
  ComputerException(const QString& info) noexcept : info_(info) {}

  virtual ~ComputerException() noexcept {}

  QString getInfo() const noexcept { return info_; }
};

#endif  // COMPUTER_EXCEPTION_H_
