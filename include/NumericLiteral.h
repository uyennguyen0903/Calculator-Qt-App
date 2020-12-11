#ifndef NUMERICAL_LITERAL_H_
#define NUMERICAL_LITERAL_H_

#include <algorithm>
#include <string>

#include "ComputerException.h"
#include "Literal.h"
#include "Operand.h"

using namespace std;

class NumericLiteral : public Literal {
 public:
  NumericLiteral() = default;

  virtual ~NumericLiteral(){};

  virtual const string Print() const = 0;

  virtual LiteralType GetLiteralType() const = 0;
};

class Integer : public NumericLiteral {
 private:
  int value_;

 public:
  Integer(int value) : value_(value){};

  int GetInt() { return value_; }

  void SetInt(int value) { value_ = value; }

  const string Print() const override { return to_string(value_); }

  LiteralType GetLiteralType() const override { return LiteralType::kInteger; }
};

class Fraction : public NumericLiteral {
 private:
  int numerator_;
  int denominator_;
  void Simplification();

 public:
  Fraction(int numerator = 0, int denominator = 1);

  int GetNumerator() { return numerator_; }

  int GetDenominator() { return denominator_; }

  void SetFraction(int numerator, int denominator);

  const string Print() const override {
    return to_string(numerator_) + "/" + to_string(denominator_);
  }

  LiteralType GetLiteralType() const override { return LiteralType::kFraction; }
};

class Real : public NumericLiteral {
 private:
  double value_;

 public:
  Real(double value) : value_(value){};

  int GetReal() { return value_; }

  void SetReal(double value) { value_ = value; }

  const string Print() const override { return to_string(value_); }

  LiteralType GetLiteralType() const override { return LiteralType::kReal; }
};

#endif  // NUMERICAL_LITERAL_H_