#pragma once
#include <cmath>

namespace MathAn {
  class Vector3 {
    double x, y, z;
  public:Vector3();
  Vector3(const double xi, const double yi, const double zi);
  Vector3(const Vector3 & i);
  double get_length() const;
  Vector3 get_normalised() const;
  Vector3 operator=(const Vector3 other);
  Vector3 operator+(const Vector3 other) const;
  Vector3 operator-(const Vector3 other) const;
  double operator*(const Vector3 other) const;
  Vector3 operator+=(const Vector3 other);
  Vector3 operator-=(const Vector3 other);
  Vector3 operator*=(const double num);
  Vector3 operator/=(const double num);
  bool operator==(const Vector3 other) const;
  bool operator!=(const Vector3 other) const;
  double get_angle(const Vector3 other) const;
  double get_x() const;
  double get_y() const;
  double get_z() const;
  friend Vector3 operator*(const Vector3 vec, const double num);
  friend Vector3 operator*(const double num, const Vector3 vec);
  friend Vector3 operator/(const Vector3 vec, const double num);
  friend Vector3 operator/(const double num, const Vector3 vec);
};
Vector3 operator*(const Vector3 vec, const double num);
Vector3 operator*(const double num, const Vector3 vec);
Vector3 operator/(const Vector3 vec, const double num);
Vector3 operator/(const double num, const Vector3 vec);
};
