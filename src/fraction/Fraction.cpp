#include "./../../include/fraction/Fraction.hpp"

namespace MathAn {
  unsigned int Fraction::gcd(unsigned int const a, unsigned int const b) const {
    if (b == 0)
  		return a;
  	return gcd(b, a % b);
  }

  void Fraction::reduce() {
    bool sign = ((numerator < 0) && (denominator < 0));
    unsigned int const tgcd = gcd(abs(numerator), abs(denominator));
    if (tgcd < 2)
      return;
    numerator /= tgcd;
    denominator /= tgcd;
    if (sign) {
      numerator *= (-1);
      denominator *= (-1);
    }
  }


  Fraction::Fraction() {
    numerator = 1;
    denominator = 1;
  }


  Fraction::Fraction(const int num, const int den) {
    numerator = num;
    denominator = den;
    reduce();
  }


  Fraction::Fraction(const Fraction & other) {
    numerator = other.numerator;
    denominator = other.denominator;
  }


  Fraction Fraction::operator=(const Fraction other) {
    numerator = other.numerator;
    denominator = other.denominator;
    return other;
  }


  Fraction Fraction::operator+(const Fraction other) const {
    Fraction answ;
    int tgcd = gcd(abs(denominator), abs(other.denominator));
    answ.denominator = denominator * other.denominator / tgcd;
    answ.numerator = (numerator*other.denominator + other.numerator*denominator)/tgcd;
    answ.reduce();
    return answ;
  }


  Fraction Fraction::operator-(const Fraction other) const {
    Fraction answ;
    int tgcd = gcd(abs(denominator), abs(other.denominator));
    answ.denominator = denominator * other.denominator / tgcd;
    answ.numerator = (numerator*other.denominator - other.numerator*denominator)/tgcd;
    answ.reduce();
    return answ;
  }


  Fraction Fraction::operator*(const Fraction other) const {
    Fraction answ;
    answ.numerator = numerator * other.numerator;
    answ.denominator = denominator * other.denominator;
    answ.reduce();
    return answ;
  }


  Fraction Fraction::operator/(const Fraction other) const {
    Fraction answ;
    answ.numerator = numerator * other.denominator;
    answ.denominator = denominator * other.numerator;
    answ.reduce();
    return answ;
  }


  Fraction Fraction::operator+=(const Fraction other) {
    int tgcd = gcd(abs(denominator), abs(other.denominator));
    denominator = denominator * other.denominator / tgcd;
    numerator = (numerator*other.denominator + other.numerator*denominator)/tgcd;
    reduce();
    return *this;
  }


  Fraction Fraction::operator-=(const Fraction other) {
    int tgcd = gcd(abs(denominator), abs(other.denominator));
    denominator = denominator * other.denominator / tgcd;
    numerator = (numerator*other.denominator - other.numerator*denominator)/tgcd;
    reduce();
    return *this;
  }


  Fraction Fraction::operator*=(const Fraction other) {
    denominator *= other.denominator;
    numerator *= other.numerator;
    reduce();
    return *this;
  }


  Fraction Fraction::operator/=(const Fraction other) {
    denominator *= other.numerator;
    numerator *= other.denominator;
    reduce();
    return *this;
  }


  bool Fraction::operator==(const Fraction other) {
    return (numerator==other.numerator) && (denominator==other.denominator);
  }


  bool Fraction::operator!=(const Fraction other) {
    return (numerator!=other.numerator) || (denominator!=other.denominator);
  }


  bool Fraction::operator<(const Fraction other) {
    return (other.numerator*denominator) < (numerator*other.denominator);
  }


  bool Fraction::operator>(const Fraction other) {
    return (other.numerator*denominator) > (numerator*other.denominator);
  }


  bool Fraction::operator<=(const Fraction other) {
    return (other.numerator*denominator) <= (numerator*other.denominator);
  }


  bool Fraction::operator>=(const Fraction other) {
    return (other.numerator*denominator) >= (numerator*other.denominator);
  }


  double Fraction::count() const {
    return double(numerator) / double(denominator);
  }


  std::string Fraction::get_str() const {
    std::string answ;
    answ += std::to_string(numerator);
    if (denominator != 1) {
      answ += "/";
      answ += std::to_string(denominator);
    }
    return answ;
  }
}
