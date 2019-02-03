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
    bool is_point_inside(const Point2 pnt) const;
    bool is_vector_parallel(const Vector2 vec) const;
    bool is_line_parallel(const Line2 ln) const;
    bool is_vector_normal(const Vector2 vec) const;
    bool is_line_normal(const Line2 ln) const;
    Line2 operator=(const Line2 other);
    bool operator==(const Line2 other) const;
    bool operator!=(const Line2 other) const;
  }
};
