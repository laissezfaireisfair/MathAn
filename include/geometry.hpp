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
    bool operator==(const Vector2 other) const;
    bool operator!=(const Vector2 other) const;
    double get_angle(const Vector2 other) const;
    double get_x() const;
    double get_y() const;
  };

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
};
