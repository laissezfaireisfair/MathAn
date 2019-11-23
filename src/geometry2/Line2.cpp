#pragma once
#include "./../../include/geometry2/Line2.hpp"

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

MathAn::Line2::Line2(const Point2 p1, const Point2 p2) {
  Vector2 vec(p1.get_movement(p2));
  *this = Line2(p1, vec);
}

MathAn::Line2::Line2(const Point2 pnt, const Line2 prlll) {
  a = prlll.a;
  b = prlll.b;
  c = (-1.0) * prlll.a * pnt.get_x() - prlll.b * pnt.get_y();
}

double MathAn::Line2::get_a() const {
  return a;
}

double MathAn::Line2::get_b() const {
  return b;
}

double MathAn::Line2::get_c() const {
  return c;
}

MathAn::Point2 MathAn::Line2::get_intersection(const Line2 other) const {
  double y = (a * other.c - other.a * c) / (other.a * b - a * other.b);
  double x = (-other.b * y - other.c) / other.a;
  return Point2(x, y);
}

MathAn::Vector2 MathAn::Line2::get_single_direction_vector() const {
  return Vector2(-b, a).get_normalised();
}

MathAn::Vector2 MathAn::Line2::get_single_normal_vector() const {
  return Vector2(a, b).get_normalised();
}

bool MathAn::Line2::is_point_inside(const Point2 pnt) const {
  return (a * pnt.get_x() + b * pnt.get_y() + c == 0);
}

bool MathAn::Line2::is_vector_parallel(const Vector2 vec) const {
  return (vec * get_single_normal_vector() == 0);
}

bool MathAn::Line2::is_vector_normal(const Vector2 vec) const {
  return (vec * get_single_direction_vector() == 0);
}

bool MathAn::Line2::is_line_parallel(const Line2 ln) const {
  return (get_single_normal_vector() * ln.get_single_direction_vector() == 0);
}

bool MathAn::Line2::is_line_normal(const Line2 ln) const {
  return (get_single_normal_vector() * ln.get_single_normal_vector() == 0);
}

MathAn::Line2 MathAn::Line2::operator=(const Line2 other) {
  a = other.a;
  b = other.b;
  c = other.c;
  return other;
}

bool MathAn::Line2::operator==(const Line2 other) const {
  return ((a / other.a == b / other.b) && (b / other.b == c / other.c));
}

bool MathAn::Line2::operator!=(const Line2 other) const {
  return !(*this == other);
}
