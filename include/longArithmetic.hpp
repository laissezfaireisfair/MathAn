#pragma once
#include <vector>
#include <string>
#include <stdexcept>

namespace MathAn {
  class LongNum {
    std::vector<bool> body;
    short sign;
  public:
    LongNum();
    LongNum(LongNum const & other);
    LongNum(int const num);
    LongNum(std::string const strNum);
    int get_int(unsigned int const notation = 10) const;
    std::string get_string(unsigned int const notation = 10) const;
    short get_sign() const;
    unsigned int get_int_digit(unsigned int const numDigit,\
        unsigned int const notation = 10) const;
    std::string get_string_digit(unsigned int const numDigit,\
        unsigned int const notation = 10) const;
    LongNum get_abs() const;
    LongNum get_negative() const;
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
