#pragma once
#include "../../include/longArithmetic/LongNum.hpp"

namespace MathAn {
  void LongNum::negative() {
    sign *= -1;
  }
  LongNum::LongNum() {
    sign = 0;
    body.push_back(0);
  }

  LongNum::LongNum(LongNum const & other) {
    sign = other.sign;
    body = other.body;
  }

  LongNum::LongNum(int const num) {
    if (num == 0) {
      sign = 0;
      body.push_back(0);
      return;
    }
    int positivedNumRest;
    if (num > 0) {
      sign = 1;
      positivedNumRest = num;
    }
    else {
      sign = -1;
      positivedNumRest = (-1) * num;
    }
    for (;positivedNumRest > 0; positivedNumRest /= 2)
      body.push_back(positivedNumRest % 2);
  }

  int LongNum::get_int() const {
    if (body.size() > 32)
      throw std::range_error("Too large for int");
    int counter = 0;
    unsigned int const bodySize = body.size();
    for (unsigned int i = 0; i < bodySize; ++i)
      counter += body[i] * std::pow(2, i);
    return counter * sign;
  }

  std::string LongNum::get_string() const {
    _LongNumConverter converter(*this);
    return converter.get_string();
  }

  short LongNum::get_sign() const {
    return sign;
  }

  LongNum LongNum::get_pow(unsigned int const exponent) const {
    LongNum answ(1);
    for (unsigned int i = 0; i < exponent; ++i)
      answ *= *this;
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
    for (unsigned int i = 0, carry = 0; i < other.body.size() || carry; i++) {
      unsigned int digSum = carry + int(body[i]) + int(other.body[i]);
      body[i] = digSum % 2;
      carry = digSum / 2;
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
    for (unsigned int i = 0, carry = 0; i < other.body.size() || carry; i++) {
      int digSum = int(body[i]) - int(other.body[i]) - carry;
      body[i] = (digSum > 0 ? digSum : 0);
      carry = (digSum < 0 ? 1 : 0);
    }
    return *this;
  }

  LongNum LongNum::operator*=(LongNum const other) {
    LongNum copy(*this);
    for (LongNum i(0); i < other; i++)
    *this += copy;
    return *this;
  }

  LongNum LongNum::operator/=(LongNum const other) {
    LongNum i = 0;
    for (LongNum accum = 0; accum <= other; ++i, accum += *this) {}
    *this = i - 1;
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
    return ((*this - other).sign() == 0);
  }

  bool LongNum::operator!=(LongNum const other) const {
    return !(*this == other);
  }

  bool LongNum::operator>(LongNum const other) const {
    return ((*this - other).sign() > 0);
  }

  bool LongNum::operator<(LongNum const other) const {
    return ((*this - other).sign() < 0);
  }

  bool LongNum::operator>=(LongNum const other) const {
    return (*this > other || *this == other);
  }

  bool LongNum::operator<=(LongNum const other) const {
    return (*this < other || *this == other);
  }

  void _LongNumConverter::increment() {
    unsigned int i = 0;
    bool need_increase_digit;
    do {
      if (body[i] == base) {
        body[i] = 0;
        ++i;
        need_increase_digit = true;
      }
      else {
        body[i] += 1;
        need_increase_digit = false;
      }
    } while(need_increase_digit);
  }

  _LongNumConverter::_LongNumConverter(LongNum const & num) {
    body = std::vector<unsigned int>(1, 0);
    sign = num.get_sign();
    for (LongNum i = num.get_abs(); i > 0; --i)
      increment();
  }

  std::string _LongNumConverter::get_string() const {
    std::string str = (sign > 0) ? "" : "-";
    for (unsigned int i = body.size() - 1; i >= 0; --i)
      str.push_back('0' + body[i]);
    return str;
  }
}
