#pragma once

namespace MathAn {
  class Vector2 {
    double x, y;
  public:
    Vector2();
    Vector2(const double xi, const double yi);
    Vector2(const Vector2 i);
    Vector2 get_normalised() const;
    double get_length() const;
    Vector2 operator+(const Vector2 other) const;
    Vector2 operator-(const Vector2 other) const;
    Vector2 operator*(const Vector2 other) const;
    double get_angle(const Vector2 other) const;
  };
};
