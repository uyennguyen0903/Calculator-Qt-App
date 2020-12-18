#ifndef NUMERICAL_LITERAL_H_
#define NUMERICAL_LITERAL_H_

#include <QString>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "ComputerException.h"
#include "Literal.h"
#include "Operand.h"
#include "math.h"

using namespace std;

class NumericLiteral : public Literal {
 public:
  NumericLiteral() = default;

  virtual ~NumericLiteral(){};

  virtual const QString Print() const = 0;

  virtual LiteralType GetLiteralType() const = 0;
};

class Integer : public NumericLiteral {
 private:
  int value_;

 public:
  Integer(int value) : value_(value){};

  int GetInt() const { return value_; }

  Integer(Integer* const num) : value_(num->GetInt()){};

  void SetInt(int value) { value_ = value; }

  const QString Print() const override { return QString::number(value_); }

  LiteralType GetLiteralType() const override { return LiteralType::kInteger; }
};

class Fraction : public NumericLiteral {
 private:
  int numerator_;
  int denominator_;
  void Simplification();

 public:
  Fraction(int numerator = 0, int denominator = 1);

  int GetNumerator() const { return numerator_; }

  int GetDenominator() const { return denominator_; }

  Fraction(Fraction* const frac)
      : numerator_(frac->GetNumerator()),
        denominator_(frac->GetDenominator()){};

  void SetFraction(int numerator, int denominator);

  const QString Print() const override {
    return QString::number(numerator_) + "/" + QString::number(denominator_);
  }

  LiteralType GetLiteralType() const override { return LiteralType::kFraction; }
};

class Real : public NumericLiteral {
 private:
  float value_;

 public:
  Real(float value) : value_(value){};

  float GetReal() const { return value_; }

  Real(Real* const num) : value_(num->GetReal()){};

  void SetReal(float value) { value_ = value; }

  const QString Print() const override {
    QString str_float = QString::fromStdString(to_string(value_));
    while (str_float != "" && str_float[str_float.size() - 1] == "0") {
      str_float.remove(str_float.size() - 1, 1);
    }
    if (str_float[str_float.size() - 1] == ".") {
      str_float.append("0");
    }
    return str_float;
  }

  LiteralType GetLiteralType() const override { return LiteralType::kReal; }
};

#endif  // NUMERICAL_LITERAL_H_