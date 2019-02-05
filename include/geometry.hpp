#pragma once
#include <cmath>

namespace MathAn {
  class Vector2 {
    double x, y;
  public:
    Vector2();
    Vector2(const double xi, const double yi);
    Vector2(const Vector2 & i);
    double get_length() const;
    Vector2 get_normalised() const;
    Vector2 operator=(const Vector2 other);
    Vector2 operator+(const Vector2 other) const;
    Vector2 operator-(const Vector2 other) const;
    double operator*(const Vector2 other) const;
    Vector2 operator+=(const Vector2 other);
    Vector2 operator-=(const Vector2 other);
    Vector2 operator*=(const double num);
    Vector2 operator/=(const double num);
    bool operator==(const Vector2 other) const;
    bool operator!=(const Vector2 other) const;
    double get_angle(const Vector2 other) const;
    double get_x() const;
    double get_y() const;
    friend Vector2 operator*(const Vector2 vec, const double num);
    friend Vector2 operator*(const double num, const Vector2 vec);
    friend Vector2 operator/(const Vector2 vec, const double num);
    friend Vector2 operator/(const double num, const Vector2 vec);
    bool is_vector_normal(const Vector2 other) const;
    bool is_vector_collinear(const Vector2 other) const;
  };
  Vector2 operator*(const Vector2 vec, const double num);
  Vector2 operator*(const double num, const Vector2 vec);
  Vector2 operator/(const Vector2 vec, const double num);
  Vector2 operator/(const double num, const Vector2 vec);

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

  class Line2 {
    double a, b, c;
  public:
    Line2();
    Line2(const double ai, const double bi, const double ci);
    Line2(const Line2 & other);
    Line2(const Point2 pnt, const Vector2 vec);
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
};
