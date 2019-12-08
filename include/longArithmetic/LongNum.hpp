#pragma once
#include <vector>
#include <string>
#include <stdexcept>
#include <cmath>

namespace MathAn {
  class LongNum {
    std::vector<bool> body;
    short sign;
    void negative();
  public:
    LongNum();
    LongNum(LongNum const & other);
    LongNum(int const num);
    int get_int() const;
    std::string get_string() const;
    short get_sign() const;
    LongNum get_abs() const;
    LongNum get_negative() const;
    LongNum get_pow(unsigned int const exponent) const;
    LongNum operator+(LongNum const other) const;
    LongNum operator-(LongNum const other) const;
    LongNum operator*(LongNum const other) const;
    LongNum operator/(LongNum const other) const;
    LongNum operator%(LongNum const other) const;
    LongNum operator+=(LongNum const other);
    LongNum operator-=(LongNum const other);
    LongNum operator*=(LongNum const other);
    LongNum operator/=(LongNum const other);
    LongNum operator%=(LongNum const other);
    LongNum operator++();
    LongNum operator--();
    LongNum operator++(int);
    LongNum operator--(int);
    bool operator==(LongNum const other) const;
    bool operator!=(LongNum const other) const;
    bool operator>(LongNum const other) const;
    bool operator<(LongNum const other) const;
    bool operator>=(LongNum const other) const;
    bool operator<=(LongNum const other) const;
  };

  class _LongNumConverter {
    unsigned int const base = 1000000000;
    std::vector<unsigned int> body;
    int sign;
    void increment();
  public:
    _LongNumConverter(LongNum const & num);
    std::string get_string() const;
  };
}
