#pragma once
#include "./../include/geometry.hpp"

MathAn::Vector2() {
  x = 1;
  y = 1;
}
MathAn::Vector2(const double xi, const double yi) {
  x = xi;
  y = yi;
}
MathAn::Vector2(const MathAn::Vector2 i) {
  x = i.x;
  y = i.y;
}
double get_length() const {
  return hypot(x, y);
}
MathAn::Vector2 get_normalised() const {
  double len = get_length();
  x /= len;
  y /= len;
}
MathAn::Vector2 operator+(const MathAn::Vector2 other) const {
  return Vector2(x + other.x, y + other.y);
}
MathAn::Vector2 operator-(const MathAn::Vector2 other) const {
  return Vector2(x - other.x, y - other.y);
}
double operator*(const MathAn::Vector2 other) const {
  return x * other.x + y * other.y;
}
double get_angle(const MathAn::Vector2 other) const {
  return (*this) * other / get_length();
}
