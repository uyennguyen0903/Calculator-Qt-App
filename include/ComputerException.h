#ifndef COMPUTER_EXCEPTION_H_
#define COMPUTER_EXCEPTION_H_

#include <stdexcept>
#include <string>

using namespace std;

class ComputerException : public exception {
  string info;

 public:
  ComputerException(const string& str) noexcept : info(str) {}
  virtual ~ComputerException() noexcept {}
  string getInfo() const noexcept { return info; }
};

#endif  // COMPUTER_EXCEPTION_H_
