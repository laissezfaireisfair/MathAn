#pragma once
#include <vector>
#include <string>
#include <stdexcept>
#include <cmath>

namespace MathAn {
  class LongNum {
    std::vector<bool> body;
    short sign;
  public:
    LongNum();
    LongNum(LongNum const & other);
    LongNum(int const num);
    int get_int() const;
    std::string get_string() const;
    short get_sign() const;
    unsigned int get_int_digit(unsigned int const numDigit) const;
    LongNum get_abs() const;
    LongNum get_negative() const;
    LongNum get_pow(unsigned int const exponent) const;
    LongNum operator+(LongNum const other) const;
    LongNum operator-(LongNum const other) const;
    LongNum operator*(LongNum const other) const;
    LongNum operator/(LongNum const other) const;
    LongNum operator+=(LongNum const other);
    LongNum operator-=(LongNum const other);
    LongNum operator*=(LongNum const other);
    LongNum operator/=(LongNum const other);
    LongNum operator++();
    LongNum operator--();
    bool operator==(LongNum const other) const;
    bool operator!=(LongNum const other) const;
    bool operator>(LongNum const other) const;
    bool operator<(LongNum const other) const;
    bool operator>=(LongNum const other) const;
    bool operator<=(LongNum const other) const;
  };
}
