#pragma once

class Complex {
  double a, b;
public:
  Complex();
  Complex(const double ai, const double bi);
  Complex(const double ai);
  Complex(const Complex & other);
  Complex operator=(const Complex & other);
  Complex operator+(const Complex & other) const;
  Complex operator-(const Complex & other) const;
  Complex operator*(const Complex & other) const;
  Complex operator/(const Complex & other) const;
  Complex operator+=(const Complex & other);
  Complex operator-=(const Complex & other);
  Complex operator*=(const Complex & other);
  Complex operator/=(const Complex & other);
  double get_abs() const;
  double get_a() const;
  double get_b() const;
  double get_arg() const;
  double get_conjugate() const;
};
