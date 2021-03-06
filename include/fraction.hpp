#pragma once
#include <cmath>
#include <string>
#include "operations.hpp"
#include "./../src/operations.cpp"

namespace MathAn {
  template <class Num>
  class Fraction {
  private:
    Num numerator, denominator;
    void reduce();
  public:
    Fraction();
    Fraction(const Num num, const Num den);
    Fraction(const Fraction & other);
    Fraction operator=(const Fraction other);
    Fraction operator+(const Fraction other) const;
    Fraction operator-(const Fraction other) const;
    Fraction operator*(const Fraction other) const;
    Fraction operator/(const Fraction other) const;
    Fraction operator+=(const Fraction other);
    Fraction operator-=(const Fraction other);
    Fraction operator*=(const Fraction other);
    Fraction operator/=(const Fraction other);
    bool operator==(const Fraction other);
    bool operator!=(const Fraction other);
    bool operator<(const Fraction other);
    bool operator>(const Fraction other);
    bool operator<=(const Fraction other);
    bool operator>=(const Fraction other);
    double count() const;
    std::string get_str() const;
  };
}
