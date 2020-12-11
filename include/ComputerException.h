#ifndef COMPUTER_EXCEPTION_H_
#define COMPUTER_EXCEPTION_H_

#include <stdexcept>
#include <string>

using namespace std;

class ComputerException : public exception {
  string info_;

 public:
  ComputerException(const string& info) noexcept : info_(info) {}

  virtual ~ComputerException() noexcept {}

  string getInfo() const noexcept { return info_; }
};

#endif  // COMPUTER_EXCEPTION_H_
