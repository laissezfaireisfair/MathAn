#pragma once
#include "./../../include/geometry2/Point2.hpp"

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
