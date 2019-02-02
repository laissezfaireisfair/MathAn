#pragma once
#include "./../include/geometry.hpp"

MathAn::Vector2() {
  x = 1;
  y = 1;
}
Vector2(const double xi, const double yi) {
  x = xi;
  y = yi;
}
Vector2(const Vector2 i) {
  x = i.x;
  y = i.y;
}
double get_length() const {
  return hypot(x, y);
}
Vector2 get_normalised() const {
  double len = get_length();
  x /= len;
  y /= len;
}
Vector2 operator+(const Vector2 other) const {
  return Vector2(x + other.x, y + other.y);
}
Vector2 operator-(const Vector2 other) const {
  return Vector2(x - other.x, y - other.y);
}
double operator*(const Vector2 other) const {
  return x * other.x + y * other.y;
}
double get_angle(const Vector2 other) const {
  return (*this) * other / get_length();
}
