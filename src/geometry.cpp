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
bool MathAn::Point2::operator==(const Point2 other) const {
  return (x == other.x) && (y == other.y);
}
bool MathAn::Point2::operator!=(const Point2 other) const {
  return (x != other.x) || (y != other.y);
}


/// Line2 functions:
MathAn::Line2::Line2() {
  a = 1;
  b = 1;
  c = 0;
}
MathAn::Line2::Line2(const double ai, const double bi, const double ci) {
  a = ai;
  b = bi;
  c = ci;
}
MathAn::Line2::Line2(const Line2 & other) {
  a = other.a;
  b = other.b;
  c = other.c;
}
MathAn::Line2::Line2(const Point2 pnt, const Vector2 vec) {
  a = vec.get_y() * (-1.0);
  b = vec.get_x();
  c = vec.get_y() * pnt.get_x() - vec.get_x() * pnt.get_y();
}
MathAn::Line2::Line2(const Point2 pnt, const Line2 prlll) {
  a = prlll.a;
  b = prlll.b;
  c = (-1.0) * prlll.a * pnt.get_x() - prlll.b * pnt.get_y();
}
double MathAn::Line2::get_a() const;
double MathAn::Line2::get_b() const;
double MathAn::Line2::get_c() const;
MathAn::Point2 MathAn::Line2::get_intersection(const Line2 other) const;
MathAn::Vector2 MathAn::Line2::get_single_direction_vector() const;
MathAn::Vector2 MathAn::Line2::get_single_normal_vector() const;
bool MathAn::Line2::is_point_inside(const Point2 pnt) const;
bool MathAn::Line2::is_vector_parallel(const Vector2 vec) const;
bool MathAn::Line2::is_line_parallel(const Line2 ln) const;
bool MathAn::Line2::is_vector_normal(const Vector2 vec) const;
bool MathAn::Line2::is_line_normal(const Line2 ln) const;
MathAn::Line2 MathAn::Line2::operator=(const Line2 other);
bool MathAn::Line2::operator==(const Line2 other) const;
bool MathAn::Line2::operator!=(const Line2 other) const;
