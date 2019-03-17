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
  bool is_vector_collinear(const Vector3 other) const;
  bool is_vector_normal(const Vector3 other) const;
};
Vector3 operator*(const Vector3 vec, const double num);
Vector3 operator*(const double num, const Vector3 vec);
Vector3 operator/(const Vector3 vec, const double num);
Vector3 operator/(const double num, const Vector3 vec);
};

class Point3 {
  double x, y, z;
public:
  Point3();
  Point3(double xi, double yi, double zi);
  Point3(const Point3 & other);
  double get_x() const;
  double get_y() const;
  double get_z() const;
  double get_dist(const Point3 other) const;
  Vector3 get_movement(const Point3 target) const;
  Point3 operator=(const Point3 other);
  Point3 operator+(const Vector3 movement) const;
  Point3 operator+=(const Vector3 movement);
  bool operator==(const Point3 other) const;
  bool operator!=(const Point3 other) const;
};
