#pragma once
#include <cmath>
#include "Vector2.hpp"

namespace MathAn {
  class Point2 {
    double x, y;
  public:
    Point2();
    Point2(double xi, double yi);
    Point2(const Point2 & other);
    double get_x() const;
    double get_y() const;
    double get_dist(const Point2 other) const;
    Vector2 get_movement(const Point2 target) const;
    Point2 operator=(const Point2 other);
    Point2 operator+(const Vector2 movement) const;
    Point2 operator+=(const Vector2 movement);
    bool operator==(const Point2 other) const;
    bool operator!=(const Point2 other) const;
  };
}
