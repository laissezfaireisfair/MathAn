#pragma once
#include "../../include/longArithmetic/LongNum.hpp"
#include <stdexcept>
#include <cmath>

namespace MathAn {
  const uint64_t LongNum::base = 10000000000000000;

  void LongNum::negative() {
    sign *= -1;
  }

  LongNum::LongNum() {
    sign = 0;
    body = std::vector<uint64_t>(1, 0);
  }

  LongNum::LongNum(LongNum const & other) {
    sign = other.sign;
    body = other.body;
  }

  LongNum::LongNum(int64_t const num) {
    body = std::vector<uint64_t>();
    if (num == 0) {
      sign = 0;
      body.push_back(0);
      return;
    }
    uint64_t positivedNumRest;
    if (num > 0) {
      sign = 1;
      positivedNumRest = num;
    }
    else {
      sign = -1;
      positivedNumRest = (-1) * num;
    }
    for (;positivedNumRest > 0; positivedNumRest /= base)
      body.push_back(positivedNumRest % base);
  }

  int64_t LongNum::get_integer() const {
    if (body.size() > 1 || body[0] > INT64_MAX)
      throw std::range_error("Too large for int64_t");
    return body[0] * sign;
  }

  std::string LongNum::get_string() const {
    std::string str;
    for (uint64_t i = 0; i < body.size(); ++i)
      for (uint64_t digit = body[i]; digit > 0; digit /= 10)
        str.insert(0, std::string(digit % 10));
    return str;
  }

  short LongNum::get_sign() const {
    return sign;
  }

  LongNum LongNum::get_pow(unsigned int const exponent) const {
    LongNum answ(1);
    for (unsigned int i = 0; i < exponent; ++i)
      answ *= *this;
    return answ;
  }

  LongNum LongNum::get_abs() const {
    LongNum answ(*this);
    if (answ.sign == -1)
      answ.sign = 1;
    return answ;
  }

  LongNum LongNum::get_negative() const {
    LongNum answ(*this);
    answ.sign *= -1;
    return answ;
  }

  LongNum LongNum::operator+(LongNum const other) const {
    LongNum a(*this);
    a += other;
    return a;
  }

  LongNum LongNum::operator-(LongNum const other) const {
    LongNum a(*this);
    a -= other;
    return a;
  }

  LongNum LongNum::operator*(LongNum const other) const {
    LongNum a(*this);
    a *= other;
    return a;
  }

  LongNum LongNum::operator/(LongNum const other) const {
    LongNum a(*this);
    a /= other;
    return a;
  }

  LongNum LongNum::operator%(LongNum const other) const {
    LongNum a(*this);
    a /= other;
    return a;
  }

  LongNum LongNum::operator+=(LongNum const other) {
    if (other.sign == 0)
      return *this;
    if (sign == 0) {
      *this = other;
      return *this;
    }
    if (sign > 0 && other.sign < 0)
      return *this -= other.get_negative();
    if (sign < 0 && other.sign > 0) {
      negative();
      *this += other;
      negative();
      return *this;
    }
    if (sign < 0 && other.sign < 0) {
      negative();
      *this -= other;
      negative();
      return *this;
    }
    for (uint64_t i = 0, carry = 0; i < other.body.size() || carry; ++i) {
      if (i == body.size())
        body.push_back(0);
      uint64_t digSum;
      if (i < other.body.size())
        digSum = carry + body[i] + other.body[i];
      else
        digSum = carry + body[i];
      body[i] = digSum % base;
      carry = digSum / base;
    }
    return *this;
  }

  LongNum LongNum::operator-=(LongNum const other) {
    if (other.sign == 0)
      return *this;
    if (sign == 0) {
      *this = other;
      return *this;
    }
    if (sign > 0 && other.sign < 0)
      return *this += other.get_negative();
    if (sign < 0 && other.sign > 0) {
      negative();
      *this -= other;
      negative();
      return *this;
    }
    if (sign < 0 && other.sign < 0) {
      negative();
      *this += other;
      negative();
      return *this;
    }
    for (uint64_t i = 0, carry = 0; i < other.body.size() || carry; i++) {
      if (i == body.size())
        body.push_back(0);
      int64_t digDiff;
      if (i < other.body.size())
        digDiff = body[i] - (carry + other.body[i]);
      else
        digDiff = body[i] - carry;
      if (digDiff >= 0)
        body[i] = digDiff;
      else {
        body[i] = 0;
        carry = abs(digDiff);
      }
    }
    return *this;
  }

  LongNum LongNum::operator*=(LongNum const other) {
    short const multSign = sign * other.sign;
    LongNum const otherAbs = other.get_abs();
    if (sign < 0)
      negative();
    LongNum copy(*this);
    for (LongNum i(0); i < otherAbs; i++)
      *this += copy;
    if (multSign < 0)
      negative();
    return *this;
  }

  LongNum LongNum::operator/=(LongNum const other) {
    short const divSign = sign * other.sign;
    LongNum const otherAbs = other.get_abs();
    if (sign < 0)
      negative();
    LongNum i = 0;
    bool isDividable = false;
    for (LongNum accum = 0; accum <= otherAbs; ++i, accum += *this)
      if (accum == otherAbs)
        isDividable = true;
    *this = i - 1;
    if (divSign < 0) {
      negative();
      if (!isDividable)
        --(*this);
    }
    return *this;
  }

  LongNum LongNum::operator%=(LongNum const other) {
    LongNum const otherAbs = other.get_abs();
    if (sign < 0)
      negative();
    LongNum accum = 0;
    for (; accum <= otherAbs; accum += *this) {
      if (accum == otherAbs) {
        *this = 0;
        return *this;
      }
    }
    *this = (accum -= other);
    return *this;
  }

  LongNum LongNum::operator++() {
    (*this) += 1;
    return *this;
  }

  LongNum LongNum::operator--() {
    (*this) -= 1;
    return *this;
  }

  LongNum LongNum::operator++(int) {
    LongNum copy(*this);
    ++(*this);
    return copy;
  }

  LongNum LongNum::operator--(int) {
    LongNum copy(*this);
    --(*this);
    return copy;
  }

  bool LongNum::operator==(LongNum const other) const {
    return ((*this - other).sign == 0);
  }

  bool LongNum::operator!=(LongNum const other) const {
    return !(*this == other);
  }

  bool LongNum::operator>(LongNum const other) const {
    return ((*this - other).sign > 0);
  }

  bool LongNum::operator<(LongNum const other) const {
    return ((*this - other).sign < 0);
  }

  bool LongNum::operator>=(LongNum const other) const {
    return (*this > other || *this == other);
  }

  bool LongNum::operator<=(LongNum const other) const {
    return (*this < other || *this == other);
  }
}
