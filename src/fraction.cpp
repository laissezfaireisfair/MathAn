#include "./../include/fraction.hpp"

template <class Num>
void MathAn::Fraction<Num>::reduce() {
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

template <class Num>
MathAn::Fraction<Num>::Fraction() {
  numerator = 1;
  denominator = 1;
}

template <class Num>
MathAn::Fraction<Num>::Fraction(const Num num, const Num den) {
  numerator = num;
  denominator = den;
  reduce();
}

template <class Num>
MathAn::Fraction<Num>::Fraction(const Fraction<Num> & other) {
  numerator = other.numerator;
  denominator = other.denominator;
}

template <class Num>
MathAn::Fraction<Num> MathAn::Fraction<Num>::operator=(const Fraction<Num> other) {
  numerator = other.numerator;
  denominator = other.denominator;
  return other;
}

template <class Num>
MathAn::Fraction<Num> MathAn::Fraction<Num>::operator+(const Fraction<Num> other) const {
  Fraction answ;
  Num tgcd = Operations::gcd(abs(denominator), abs(other.denominator));
  answ.denominator = denominator * other.denominator / tgcd;
  answ.numerator = (numerator*other.denominator + other.numerator*denominator)/tgcd;
  answ.reduce();
  return answ;
}

template <class Num>
MathAn::Fraction<Num> MathAn::Fraction<Num>::operator-(const Fraction<Num> other) const {
  Fraction answ;
  Num tgcd = Operations::gcd(abs(denominator), abs(other.denominator));
  answ.denominator = denominator * other.denominator / tgcd;
  answ.numerator = (numerator*other.denominator - other.numerator*denominator)/tgcd;
  answ.reduce();
  return answ;
}

template <class Num>
MathAn::Fraction<Num> MathAn::Fraction<Num>::operator*(const Fraction<Num> other) const {
  Fraction answ;
  answ.numerator = numerator * other.numerator;
  answ.denominator = denominator * other.denominator;
  answ.reduce();
  return answ;
}

template <class Num>
MathAn::Fraction<Num> MathAn::Fraction<Num>::operator/(const Fraction<Num> other) const {
  Fraction answ;
  answ.numerator = numerator * other.denominator;
  answ.denominator = denominator * other.numerator;
  answ.reduce();
  return answ;
}

template <class Num>
MathAn::Fraction<Num> MathAn::Fraction<Num>::operator+=(const Fraction<Num> other) {
  Num tgcd = Operations::gcd(abs(denominator), abs(other.denominator));
  denominator = denominator * other.denominator / tgcd;
  numerator = (numerator*other.denominator + other.numerator*denominator)/tgcd;
  reduce();
  return *this;
}

template <class Num>
MathAn::Fraction<Num> MathAn::Fraction<Num>::operator-=(const Fraction<Num> other) {
  Num tgcd = Operations::gcd(abs(denominator), abs(other.denominator));
  denominator = denominator * other.denominator / tgcd;
  numerator = (numerator*other.denominator - other.numerator*denominator)/tgcd;
  reduce();
  return *this;
}

template <class Num>
MathAn::Fraction<Num> MathAn::Fraction<Num>::operator*=(const Fraction<Num> other) {
  denominator *= other.denominator;
  numerator *= other.numerator;
  reduce();
  return *this;
}

template <class Num>
MathAn::Fraction<Num> MathAn::Fraction<Num>::operator/=(const Fraction<Num> other) {
  denominator *= other.numerator;
  numerator *= other.denominator;
  reduce();
  return *this;
}

template <class Num>
bool MathAn::Fraction<Num>::operator==(const Fraction<Num> other) {
  return (numerator==other.numerator) && (denominator==other.denominator);
}

template <class Num>
bool MathAn::Fraction<Num>::operator!=(const Fraction<Num> other) {
  return (numerator!=other.numerator) || (denominator!=other.denominator);
}

template <class Num>
bool MathAn::Fraction<Num>::operator<(const Fraction<Num> other) {
  return (other.numerator*denominator) < (numerator*other.denominator);
}

template <class Num>
bool MathAn::Fraction<Num>::operator>(const Fraction<Num> other) {
  return (other.numerator*denominator) > (numerator*other.denominator);
}

template <class Num>
bool MathAn::Fraction<Num>::operator<=(const Fraction<Num> other) {
  return (other.numerator*denominator) <= (numerator*other.denominator);
}

template <class Num>
bool MathAn::Fraction<Num>::operator>=(const Fraction<Num> other) {
  return (other.numerator*denominator) >= (numerator*other.denominator);
}

template <class Num>
double MathAn::Fraction<Num>::count() const {
  return double(numerator) / double(denominator);
}

template <class Num>
std::string MathAn::Fraction<Num>::get_str() const {
  std::string answ;
  answ += std::to_string(numerator);
  if (denominator != 1) {
    answ += "/";
    answ += std::to_string(denominator);
  }
  return answ;
}
