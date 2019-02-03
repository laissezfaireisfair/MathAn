#pragma once
#include "./../include/geometry.hpp"

/// Vector2 functions:
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
double MathAn::Vector2::get_angle(const MathAn::Vector2 other) const {
  return acos((*this) * other / get_length() / other.get_length());
}
double MathAn::Vector2::get_x() const {
  return x;
}
double MathAn::Vector2::get_y() const {
  return y;
}

/// Point2 functions:
MathAn::Point2::Point2() {
  x = 0;
  y = 0;
}
MathAn::Point2::Point2(double xi, double yi) {
  x = xi;
  y = yi;
}
MathAn::Point2::Point2(const MathAn::Point2 & other) {
  x = other.x;
  y = other.y;
}
double MathAn::Point2::get_x() const {
  return x;
}
double MathAn::Point2::get_y() const {
  return y;
}
double MathAn::Point2::get_dist(const MathAn::Point2 other) const {
  return hypot(other.x - x, other.y - y);
}
MathAn::Vector2 MathAn::Point2::get_movement(const MathAn::Point2 target) const {
  return Vector2(target.x - x, target.y - y);
}
MathAn::Point2 MathAn::Point2::operator=(const MathAn::Point2 other){
  x = other.x;
  y = other.y;
  return other;
}
MathAn::Point2 MathAn::Point2::operator+(const MathAn::Vector2 movement) const {
  return Point2(x + movement.get_x(), y + movement.get_y());
}
MathAn::Point2 MathAn::Point2::operator+=(const MathAn::Vector2 movement) {
  x += movement.get_x();
  y += movement.get_y();
  return *this;
}
