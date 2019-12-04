#pragma once
#include "../../include/longArithmetic/LongNum.hpp"

namespace MathAn {
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

  std::string LongNum::get_string() const;

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

  LongNum LongNum::operator+=(LongNum const other);

  LongNum LongNum::operator-=(LongNum const other);

  LongNum LongNum::operator*=(LongNum const other);

  LongNum LongNum::operator/=(LongNum const other);

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
}
