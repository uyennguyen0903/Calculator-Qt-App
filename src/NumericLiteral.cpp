#include "NumericLiteral.h"
#include "GCD.h"

Fraction::Fraction(long numerator, long denominator) {
  SetFraction(numerator, denominator);
}

void Fraction::SetFraction(long numerator, long denominator) {
  if (!denominator)
    throw(ComputerException("Dénominateur doit être non null."));
  numerator_ = numerator;
  denominator_ = denominator;
  Simplification();
}

void Fraction::Simplification() {
  if (!numerator_) denominator_ = 1;

  long gcd = __gcd(numerator_, denominator_);
  numerator_ /= gcd;
  denominator_ /= gcd;

  if (denominator_ < 0) {
    denominator_ = -denominator_;
    numerator_ = -numerator_;
  }
}
