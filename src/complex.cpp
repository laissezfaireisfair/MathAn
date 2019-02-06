#include "./../include/complex.hpp"

MathAn::Complex::Complex() {
  a = 1;
  b = 0;
}
MathAn::Complex::Complex(const double ai, const double bi) {
  a = ai;
  b = bi;
}
MathAn::Complex::Complex(const double ai) {
  a = ai;
  b = 0;
}
MathAn::Complex::Complex(const Complex & other) {
  a = other.a;
  b = other.b;
}
MathAn::Complex MathAn::Complex::operator=(const Complex other) {
  a = other.a;
  b = other.b;
  return other;
}
MathAn::Complex MathAn::Complex::operator+(const Complex other) const {
  return Complex(a + other.a, b + other.b);
}
MathAn::Complex MathAn::Complex::operator-(const Complex other) const {
  return Complex(a - other.a, b - other.b);
}
MathAn::Complex MathAn::Complex::operator*(const Complex other) const {
  return Complex(a * other.a - b * other.b, a * other.b + b * other.a);
}
MathAn::Complex MathAn::Complex::operator/(const Complex other) const {
  double at = (a*other.a + b*other.b)/(other.a*other.a + other.b*other.b);
  double bt = (b*other.a - a*other.b)/(other.a*other.a + other.b*other.b);
  return Complex(at, bt);
}
MathAn::Complex MathAn::Complex::operator+=(const Complex other) {
  a += other.a;
  b += other.b;
  return (*this);
}
MathAn::Complex MathAn::Complex::operator-=(const Complex other) {
  a -= other.a;
  b -= other.b;
  return (*this);
}
MathAn::Complex MathAn::Complex::operator*=(const Complex other) {
  double at = a * other.a - b * other.b;
  b = a * other.b + b * other.a;
  a = at;
  return (*this);
}
MathAn::Complex MathAn::Complex::operator/=(const Complex other) {
  double at = (a*other.a + b*other.b)/(other.a*other.a + other.b*other.b);
  b = (b*other.a - a*other.b)/(other.a*other.a + other.b*other.b);
  a = at;
  return (*this);
}
double MathAn::Complex::get_abs() const {
  return std::hypot(a, b);
}
double MathAn::Complex::get_a() const {
  return a;
}
double MathAn::Complex::get_b() const {
  return b;
}
double MathAn::Complex::get_arg() const {
  return std::acos(a / get_abs());
}
MathAn::Complex MathAn::Complex::get_conjugate() const {
  return Complex(a, -b);
}
bool MathAn::Complex::operator==(const Complex other) const {
  return (a == other.a) && (b == other.b);
}
bool MathAn::Complex::operator!=(const Complex other) const {
  return !(*this == other);
}
