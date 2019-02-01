#include "./../include/fraction.hpp"
using namespace MathAn;

void MathAn::Fraction::reduce() {
  bool sign = ((numerator < 0) && (denominator < 0));
  Num tgcd = Operations::gcd<Num>(abs(numerator), abs(denominator));
  if (tgcd < 2)
    return;
  numerator /= tgcd;
  denominator /= tgcd;
  if (sign) {
    numerator *= (-1);
    denominator *= (-1);
  }
}

MathAn::Fraction::Fraction() {
  numerator = 1;
  denominator = 1;
}

MathAn::Fraction::Fraction(const Num num, const Num den) {
  numerator = num;
  denominator = den;
  reduce();
}

MathAn::Fraction::Fraction(const Fraction & other) {
  numerator = other.numerator;
  denominator = other.denominator;
}

Fraction MathAn::Fraction::operator=(const Fraction other) {
  numerator = other.numerator;
  denominator = other.denominator;
}

Fraction MathAn::Fraction::operator+(const Fraction other) const {
  Fraction answ;
  Num tgcd = Operations::gcd(abs(denominator), abs(other.denominator));
  answ.denominator = denominator * other.denominator / tgcd;
  answ.numerator = (numerator*other.denominator + other.numerator*denominator)/tgcd;
  answ.reduce();
  return answ;
}
Fraction MathAn::Fraction::operator-(const Fraction other) const {
  Fraction answ;
  Num tgcd = Operations::gcd(abs(denominator), abs(other.denominator));
  answ.denominator = denominator * other.denominator / tgcd;
  answ.numerator = (numerator*other.denominator - other.numerator*denominator)/tgcd;
  answ.reduce();
  return answ;
}
Fraction MathAn::Fraction::operator*(const Fraction other) const {
  Fraction answ;
  answ.numerator = numerator * other.numerator;
  answ.denominator = denominator * other.denominator;
  answ.reduce();
  return answ;
}
Fraction MathAn::Fraction::operator/(const Fraction other) const {
  Fraction answ;
  answ.numerator = numerator * other.denominator;
  answ.denominator = denominator * other.numerator;
  answ.reduce();
  return answ;
}
Fraction MathAn::Fraction::operator+=(const Fraction other) {
  Num tgcd = Operations::gcd(abs(denominator), abs(other.denominator));
  denominator = denominator * other.denominator / tgcd;
  numerator = (numerator*other.denominator + other.numerator*denominator)/tgcd;
  reduce();
  return *this;
}
Fraction MathAn::Fraction::operator-=(const Fraction other) {
  Num tgcd = Operations::gcd(abs(denominator), abs(other.denominator));
  denominator = denominator * other.denominator / tgcd;
  numerator = (numerator*other.denominator - other.numerator*denominator)/tgcd;
  reduce();
  return *this;
}
Fraction MathAn::Fraction::operator*=(const Fraction other) {
  denominator *= other.denominator;
  numerator *= other.numerator;
  reduce();
  return *this;
}
Fraction MathAn::Fraction::operator/=(const Fraction other) {
  denominator *= other.numerator;
  numerator *= other.denominator;
  reduce();
  return *this;
}
bool MathAn::Fraction::operator==(const Fraction other) {
  return (numerator==other.numerator) && (denominator==other.denominator);
}
bool MathAn::Fraction::operator!=(const Fraction other) {
  return (numerator!=other.numerator) || (denominator!=other.denominator);
}
bool MathAn::Fraction::operator<(const Fraction other) {
  return (numerator*other.denominator) > (other.numerator*denominator);
}
bool MathAn::Fraction::operator>(const Fraction other) {
  return (numerator*other.denominator) < (other.numerator*denominator);
}
bool MathAn::Fraction::operator<=(const Fraction other) {
  return (numerator*other.denominator) <= (other.numerator*denominator);
}
bool MathAn::Fraction::operator>=(const Fraction other) {
  return (numerator*other.denominator) >= (other.numerator*denominator);
}
double MathAn::Fraction::count() const {
  return double(numerator) / double(denominator);
}
std::string MathAn::Fraction::get_str() const {
  std::string answ;
  answ += std::to_string(numerator);
  if (denominator != 1) {
    answ += "/";
    answ += std::to_string(denominator);
  }
  return answ;
}
