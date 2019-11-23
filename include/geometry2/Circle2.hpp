#pragma once
#include <cmath>
#include "Vector2.hpp"
#include "Point2.hpp"

namespace MathAn {
  class Circle2 {
    Point2 centre;
    double radius;
  public:
    Circle2();
    Circle2(Point2 cntri, double radi);
    Circle2(const Circle2 & other);
    Point2 get_centre() const;
    double get_radius() const;
    Circle2 operator=(const Circle2 other);
    bool operator==(const Circle2 other) const;
    bool operator!=(const Circle2 other) const;
    bool operator>(const Circle2 other) const;
    bool operator<(const Circle2 other) const;
    bool operator>=(const Circle2 other) const;
    bool operator<=(const Circle2 other) const;
    bool is_inside(const Point2 pnt) const;
    bool is_on_the_border(const Point2 pnt) const;
    bool is_outside(const Point2 pnt) const;
    bool is_match(const Circle2 other) const;
    bool is_cross(const Circle2 other) const;
    bool is_touch(const Circle2 other) const;
    Circle2 get_moved(const Vector2 movement) const;
  };
}
