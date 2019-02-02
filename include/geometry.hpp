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
    double get_angle(const Vector2 other) const;
    double get_x() const;
    double get_y() const;
  };
};
