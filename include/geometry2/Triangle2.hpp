#pragma once

namespace MathAn {
  class Vector2;

  class Point2;

  class Triangle2 {
    Point2 a, b, c;
  public:
    Triangle2();
    Triangle2(const Point2 ai, const Point2 bi, const Point2 ci);
    Triangle2(const Line2 ln1, const Line2 ln2, const Line2 ln3);
    Triangle2(const Triangle2 & other);
    Point2 get_a() const;
    Point2 get_b() const;
    Point2 get_c() const;
    Triangle2 operator=(const Triangle2 other);
    bool operator==(const Triangle2 other) const;
    bool operator!=(const Triangle2 other) const;
    bool is_inside(const Point2 pnt) const;
    bool is_on_the_border(const Point2 pnt) const;
    Triangle2 get_moved(const Vector2 movement) const;
    double count_square() const;
  };
}
