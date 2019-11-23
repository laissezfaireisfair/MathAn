#pragma once
#include "./../../include/geometry2/Vector2.hpp"

MathAn::Vector2::Vector2() {
  x = 1;
  y = 1;
}

MathAn::Vector2::Vector2(const double xi, const double yi) {
  x = xi;
  y = yi;
}

MathAn::Vector2::Vector2(const MathAn::Vector2 & i) {
  x = i.x;
  y = i.y;
}

double MathAn::Vector2::get_length() const {
  return hypot(x, y);
}

MathAn::Vector2 MathAn::Vector2::get_normalised() const {
  double len = get_length();
  return Vector2(x/len, y/len);
}

MathAn::Vector2 MathAn::Vector2::operator=(const MathAn::Vector2 other){
  x = other.x;
  y = other.y;
  return other;
}

MathAn::Vector2 MathAn::Vector2::operator+(const MathAn::Vector2 other) const {
  return Vector2(x + other.x, y + other.y);
}

MathAn::Vector2 MathAn::Vector2::operator-(const MathAn::Vector2 other) const {
  return Vector2(x - other.x, y - other.y);
}

double MathAn::Vector2::operator*(const MathAn::Vector2 other) const {
  return x * other.x + y * other.y;
}

MathAn::Vector2 MathAn::Vector2::operator+=(const Vector2 other) {
  x += other.x;
  y += other.y;
  return (*this);
}

MathAn::Vector2 MathAn::Vector2::operator-=(const Vector2 other) {
  x -= other.x;
  y -= other.y;
  return (*this);
}

MathAn::Vector2 MathAn::Vector2::operator*=(const double num) {
  x *= num;
  y *= num;
  return (*this);
}

MathAn::Vector2 MathAn::Vector2::operator/=(const double num) {
  x /= num;
  y /= num;
  return (*this);
}

double MathAn::Vector2::get_angle(const MathAn::Vector2 other) const {
  return acos((*this) * other / get_length() / other.get_length());
}

double MathAn::Vector2::get_x() const {
  return x;
}

double MathAn::Vector2::get_y() const {
  return y;
}

bool MathAn::Vector2::operator==(const Vector2 other) const {
  return (x == other.x) && (y == other.y);
}

bool MathAn::Vector2::operator!=(const Vector2 other) const {
  return (x != other.x) || (y != other.y);
}

MathAn::Vector2 MathAn::operator*(const Vector2 vec, const double num) {
  return Vector2(vec.x * num, vec.y * num);
}

MathAn::Vector2 MathAn::operator*(const double num, const Vector2 vec) {
  return Vector2(vec.x * num, vec.y * num);
}

MathAn::Vector2 MathAn::operator/(const Vector2 vec, const double num) {
  return Vector2(vec.x / num, vec.y / num);
}

MathAn::Vector2 MathAn::operator/(const double num, const Vector2 vec) {
  return Vector2(vec.x / num, vec.y / num);
}

bool MathAn::Vector2::is_vector_collinear(const Vector2 other) const {
  return ((*this) * Vector2((-other.y), other.x) == 0);
}

bool MathAn::Vector2::is_vector_normal(const Vector2 other) const {
  return ((*this) * other == 0);
}
