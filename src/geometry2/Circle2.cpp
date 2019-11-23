#pragma once
#include "./../../include/geometry2/Circle2.hpp"

MathAn::Circle2::Circle2() {
  centre = Point2(0, 0);
  radius = 1;
}

MathAn::Circle2::Circle2(Point2 cntri, double radi) {
  centre = cntri;
  radius = radi;
}

MathAn::Circle2::Circle2(const Circle2 & other) {
  centre = other.centre;
  radius = other.radius;
}

MathAn::Point2 MathAn::Circle2::get_centre() const {
  return centre;
}

double MathAn::Circle2::get_radius() const {
  return radius;
}

MathAn::Circle2 MathAn::Circle2::operator=(const Circle2 other) {
  centre = other.centre;
  radius = other.radius;
  return other;
}

bool MathAn::Circle2::operator==(const Circle2 other) const {
  return radius == other.radius;
}

bool MathAn::Circle2::operator!=(const Circle2 other) const {
  return radius != other.radius;
}

bool MathAn::Circle2::operator>(const Circle2 other) const {
  return radius > other.radius;
}

bool MathAn::Circle2::operator<(const Circle2 other) const {
  return radius < other.radius;
}

bool MathAn::Circle2::operator>=(const Circle2 other) const {
  return radius >= other.radius;
}

bool MathAn::Circle2::operator<=(const Circle2 other) const {
  return radius <= other.radius;
}

bool MathAn::Circle2::is_inside(const Point2 pnt) const {
  return centre.get_dist(pnt) < radius;
}

bool MathAn::Circle2::is_on_the_border(const Point2 pnt) const {
  return centre.get_dist(pnt) == radius;
}

bool MathAn::Circle2::is_outside(const Point2 pnt) const {
  return centre.get_dist(pnt) > radius;
}

bool MathAn::Circle2::is_match(const Circle2 other) const {
  return (radius == other.radius) && (centre == other.centre);
}

bool MathAn::Circle2::is_cross(const Circle2 other) const {
  return (centre.get_dist(other.centre)) < (radius + other.radius);
}

bool MathAn::Circle2::is_touch(const Circle2 other) const {
  return (centre.get_dist(other.centre)) == (radius + other.radius);
}

MathAn::Circle2 MathAn::Circle2::get_moved(const Vector2 movement) const {
  return Circle2((centre + movement), radius);
}
