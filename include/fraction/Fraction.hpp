#pragma once
#include <cmath>
#include <string>

namespace MathAn {
  class Fraction {
  private:
    int numerator, denominator;
    static unsigned int gcd(unsigned int const a, unsigned int const b) const;
    void reduce();
  public:
    Fraction();
    Fraction(int const numerator, int const denominator);
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
