#pragma once
#include "./../../include/geometry2/Point2.hpp"

namespace MathAn {
  Point2::Point2() {
    x = 0;
    y = 0;
  }

  Point2::Point2(double xi, double yi) {
    x = xi;
    y = yi;
  }

  Point2::Point2(const Point2 & other) {
    x = other.x;
    y = other.y;
  }

  double Point2::get_x() const {
    return x;
  }

  double Point2::get_y() const {
    return y;
  }

  double Point2::get_dist(const Point2 other) const {
    return hypot(other.x - x, other.y - y);
  }

  Vector2 Point2::get_movement(const Point2 target) const {
    return Vector2(target.x - x, target.y - y);
  }

  Point2 Point2::operator=(const Point2 other){
    x = other.x;
    y = other.y;
    return other;
  }

  Point2 Point2::operator+(const Vector2 movement) const {
    return Point2(x + movement.get_x(), y + movement.get_y());
  }

  Point2 Point2::operator+=(const Vector2 movement) {
    x += movement.get_x();
    y += movement.get_y();
    return *this;
  }

  bool Point2::operator==(const Point2 other) const {
    return (x == other.x) && (y == other.y);
  }

  bool Point2::operator!=(const Point2 other) const {
    return (x != other.x) || (y != other.y);
  }
}
