#include "./../include/fraction.hpp"
using namespace MathAn;

void Fraction::reduce() const {
  Num gcd = Operations::gcd(numerator, denominator);
  if (gcd == 1)
    return;
  numerator /= gcd;
  denominator /= gcd;
}
