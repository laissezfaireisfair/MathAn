#include "./../include/fraction.hpp"
using namespace MathAn;

void Fraction::reduce() const {
  Num gcd = Operations::gcd(numerator, denominator);
  if (gcd <= 2)
    return;
  numerator /= gcd;
  denominator /= gcd;
}

Fraction::Fraction() {
  numerator = 1;
  denominator = 1;
}

Fraction::Fraction(const Num num, const Num den) {
  numerator = num;
  denominator = den;
  reduce();
}

Fraction(const Fraction other) {
  numerator = other.numerator;
  denominator = other.denominator;
}
