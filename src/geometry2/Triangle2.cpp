#pragma once
#include "./../../include/geometry2/Triangle2.hpp"
#include "./../../include/geometry2/Vector2.hpp"
#include "./../../include/geometry2/Point2.hpp"
#include <cmath>

namespace MathAn {
  Triangle2::Triangle2() {
    a = Point2(0, 0);
    b = Point2(1, 1);
    c = Point2(2, 0);
  }

  Triangle2::Triangle2(const Point2 ai, const Point2 bi, const Point2 ci) {
    a = ai;
    b = bi;
    c = ci;
  }

  Triangle2::Triangle2(const Line2 ln1, const Line2 ln2, const Line2 ln3) {
    a = ln1.get_intersection(ln2);
    b = ln2.get_intersection(ln3);
    c = ln3.get_intersection(ln1);
  }

  Triangle2::Triangle2(const Triangle2 & other) {
    a = other.a;
    b = other.b;
    c = other.c;
  }

  Point2 Triangle2::get_a() const {
    return a;
  }

  Point2 Triangle2::get_b() const {
    return b;
  }

  Point2 Triangle2::get_c() const {
    return c;
  }

  Triangle2 Triangle2::operator=(const Triangle2 other) {
    a = other.a;
    b = other.b;
    c = other.c;
    return other;
  }

  bool Triangle2::operator==(const Triangle2 other) const{
    if (a.get_movement(b) != other.a.get_movement(other.b))
      return false;
    if (a.get_movement(c) != other.a.get_movement(other.c))
      return false;
    return true;
  }

  bool Triangle2::operator!=(const Triangle2 other) const{
    return !((*this) == other);
  }

  bool Triangle2::is_on_the_border(const Point2 pnt) const {
    if (Line2(a, b).is_point_inside(pnt))
      return true;
    if (Line2(b, c).is_point_inside(pnt))
      return true;
    if (Line2(c, a).is_point_inside(pnt))
      return true;
    return false;
  }

  Triangle2 Triangle2::get_moved(const Vector2 movement) const {
    return Triangle2(a + movement, b + movement, c + movement);
  }

  double Triangle2::count_square() const {
    double t1 = a.get_dist(b), t2 = b.get_dist(c), t3 = c.get_dist(a);
    double p = (t1 + t2 + t3) / 2;
    return sqrt(p*(p-t1)*(p-t2)*(p-t3));
  }

  bool Triangle2::is_inside(const Point2 pnt) const {
    if (is_on_the_border(pnt))
      return false;
    Triangle2 t1(a, b, pnt), t2(a, c, pnt), t3(b, c, pnt);
    double s = t1.count_square() + t2.count_square() + t3.count_square();
    return count_square() == s;
  }
}
