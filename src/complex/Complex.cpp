#include "./../../include/complex/Complex.hpp"

namespace MathAn {
  Complex::Complex() {
    a = 1;
    b = 0;
  }
  Complex::Complex(const double ai, const double bi) {
    a = ai;
    b = bi;
  }
  Complex::Complex(const double ai) {
    a = ai;
    b = 0;
  }
  Complex::Complex(const Complex & other) {
    a = other.a;
    b = other.b;
  }
  Complex Complex::operator=(const Complex other) {
    a = other.a;
    b = other.b;
    return other;
  }
  Complex Complex::operator+(const Complex other) const {
    return Complex(a + other.a, b + other.b);
  }
  Complex Complex::operator-(const Complex other) const {
    return Complex(a - other.a, b - other.b);
  }
  Complex Complex::operator*(const Complex other) const {
    return Complex(a * other.a - b * other.b, a * other.b + b * other.a);
  }
  Complex Complex::operator/(const Complex other) const {
    double at = (a*other.a + b*other.b)/(other.a*other.a + other.b*other.b);
    double bt = (b*other.a - a*other.b)/(other.a*other.a + other.b*other.b);
    return Complex(at, bt);
  }
  Complex Complex::operator+=(const Complex other) {
    a += other.a;
    b += other.b;
    return (*this);
  }
  Complex Complex::operator-=(const Complex other) {
    a -= other.a;
    b -= other.b;
    return (*this);
  }
  Complex Complex::operator*=(const Complex other) {
    double at = a * other.a - b * other.b;
    b = a * other.b + b * other.a;
    a = at;
    return (*this);
  }
  Complex Complex::operator/=(const Complex other) {
    double at = (a*other.a + b*other.b)/(other.a*other.a + other.b*other.b);
    b = (b*other.a - a*other.b)/(other.a*other.a + other.b*other.b);
    a = at;
    return (*this);
  }
  double Complex::get_abs() const {
    return std::hypot(a, b);
  }
  double Complex::get_a() const {
    return a;
  }
  double Complex::get_b() const {
    return b;
  }
  double Complex::get_arg() const {
    return std::acos(a / get_abs());
  }
  Complex Complex::get_conjugate() const {
    return Complex(a, -b);
  }
  bool Complex::operator==(const Complex other) const {
    return (a == other.a) && (b == other.b);
  }
  bool Complex::operator!=(const Complex other) const {
    return !(*this == other);
  }
}
