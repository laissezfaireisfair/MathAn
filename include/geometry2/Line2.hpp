#pragma once

namespace MathAn {
  class Vector2;

  class Point2;

  class Line2 {
    double a, b, c;
  public:
    Line2();
    Line2(const double ai, const double bi, const double ci);
    Line2(const Line2 & other);
    Line2(const Point2 pnt, const Vector2 vec);
    Line2(const Point2 p1, const Point2 p2);
    Line2(const Point2 pnt, const Line2 prlll);
    double get_a() const;
    double get_b() const;
    double get_c() const;
    Point2 get_intersection(const Line2 other) const;
    Vector2 get_single_direction_vector() const;
    Vector2 get_single_normal_vector() const;
    bool is_point_inside(const Point2 pnt) const;
    bool is_vector_parallel(const Vector2 vec) const;
    bool is_line_parallel(const Line2 ln) const;
    bool is_vector_normal(const Vector2 vec) const;
    bool is_line_normal(const Line2 ln) const;
    Line2 operator=(const Line2 other);
    bool operator==(const Line2 other) const;
    bool operator!=(const Line2 other) const;
  };
}
