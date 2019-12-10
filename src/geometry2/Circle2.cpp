#pragma once
#include "./../../include/geometry2/Circle2.hpp"
#include "./../../include/geometry2/Vector2.hpp"
#include "./../../include/geometry2/Point2.hpp"
#include <cmath>

namespace MathAn {
  Circle2::Circle2() {
    centre = Point2(0, 0);
    radius = 1;
  }

  Circle2::Circle2(Point2 cntri, double radi) {
    centre = cntri;
    radius = radi;
  }

  Circle2::Circle2(const Circle2 & other) {
    centre = other.centre;
    radius = other.radius;
  }

  Point2 Circle2::get_centre() const {
    return centre;
  }

  double Circle2::get_radius() const {
    return radius;
  }

  Circle2 Circle2::operator=(const Circle2 other) {
    centre = other.centre;
    radius = other.radius;
    return other;
  }

  bool Circle2::operator==(const Circle2 other) const {
    return radius == other.radius;
  }

  bool Circle2::operator!=(const Circle2 other) const {
    return radius != other.radius;
  }

  bool Circle2::operator>(const Circle2 other) const {
    return radius > other.radius;
  }

  bool Circle2::operator<(const Circle2 other) const {
    return radius < other.radius;
  }

  bool Circle2::operator>=(const Circle2 other) const {
    return radius >= other.radius;
  }

  bool Circle2::operator<=(const Circle2 other) const {
    return radius <= other.radius;
  }

  bool Circle2::is_inside(const Point2 pnt) const {
    return centre.get_dist(pnt) < radius;
  }

  bool Circle2::is_on_the_border(const Point2 pnt) const {
    return centre.get_dist(pnt) == radius;
  }

  bool Circle2::is_outside(const Point2 pnt) const {
    return centre.get_dist(pnt) > radius;
  }

  bool Circle2::is_match(const Circle2 other) const {
    return (radius == other.radius) && (centre == other.centre);
  }

  bool Circle2::is_cross(const Circle2 other) const {
    return (centre.get_dist(other.centre)) < (radius + other.radius);
  }

  bool Circle2::is_touch(const Circle2 other) const {
    return (centre.get_dist(other.centre)) == (radius + other.radius);
  }

  Circle2 Circle2::get_moved(const Vector2 movement) const {
    return Circle2((centre + movement), radius);
  }
}
