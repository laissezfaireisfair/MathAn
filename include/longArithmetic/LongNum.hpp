#pragma once
#include <vector>
#include <string>
#include <cstdint>

namespace MathAn {
  class LongNum {
    std::vector<uint64_t> body;
    static uint64_t const base;
    short sign;
    void negative();
  public:
    LongNum();
    LongNum(LongNum const & other);
    LongNum(int64_t const num);
    int64_t get_integer() const;
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
}
