#pragma once
#include "../../include/longArithmetic/LongNum.hpp"

MathAn::LongNum::LongNum() {
  sign = 0;
  body.push_back(0);
}
MathAn::LongNum::LongNum(LongNum const & other) {
  sign = other.sign;
  body = other.body;
}
MathAn::LongNum::LongNum(int const num) { //TODO: string initialisalion based on
  if (num == 0) {                         //      short 10->2 notation algorithm
    sign = 0;
    body.push_back(0);
    return;
  }
  if (num > 0) {
    sign = 1;
    int positivedNumRest = num;
  }
  else {
    sign = -1;
    int positivedNumRest = (-1) * num;
  }
  for (;positivedNumRest > 0; positivedNumRest /= 2)
    body.push_back(positivedNumRest % 2);
}
int MathAn::LongNum::get_int() const {
  if (body.size() > 32)
    throw std::range_error;
  int counter = 0;
  unsigned int const bodySize = body.size();
  for (unsigned int i = 0; i < bodySize; ++i)
    counter += body[i] * std::pow(2, i);
  return counter * sign;
}
std::string MathAn::LongNum::get_string() const;
short MathAn::LongNum::get_sign() const {
  return sign;
}
unsigned int MathAn::LongNum::get_int_digit(unsigned int const numDigit) const;
std::string MathAn::LongNum::get_string_digit(unsigned int const numDigit) const;
MathAn::LongNum::LongNum MathAn::LongNum::get_pow(unsigned int const exponent) const {
  LongNum answ = LongNum(1);
  for (unsigned int i = 0; i < exponent; ++i)
    answ *= *this;
}
MathAn::LongNum::LongNum MathAn::LongNum::get_abs() const {
  LongNum answ = *this;
  if (answ.sign == -1)
    answ.sign = 1;
  return answ;
}
MathAn::LongNum::LongNum MathAn::LongNum::get_negative() const {
  LongNum answ = *this;
  answ.sign *= -1;
  return answ;
}
MathAn::LongNum::LongNum MathAn::LongNum::operator+(LongNum const other) const;
MathAn::LongNum::LongNum MathAn::LongNum::operator-(LongNum const other) const;
MathAn::LongNum::LongNum MathAn::LongNum::operator*(LongNum const other) const;
MathAn::LongNum::LongNum MathAn::LongNum::operator/(LongNum const other) const;
MathAn::LongNum::LongNum MathAn::LongNum::operator+=(LongNum const other);
MathAn::LongNum::LongNum MathAn::LongNum::operator-=(LongNum const other);
MathAn::LongNum::LongNum MathAn::LongNum::operator*=(LongNum const other);
MathAn::LongNum::LongNum MathAn::LongNum::operator/=(LongNum const other);
MathAn::LongNum::LongNum MathAn::LongNum::operator++();
MathAn::LongNum::LongNum MathAn::LongNum::operator--();
bool MathAn::LongNum::operator==(LongNum const other) const;
bool MathAn::LongNum::operator!=(LongNum const other) const;
bool MathAn::LongNum::operator>(LongNum const other) const;
bool MathAn::LongNum::operator<(LongNum const other) const;
bool MathAn::LongNum::operator>=(LongNum const other) const;
bool MathAn::LongNum::operator<=(LongNum const other) const;
