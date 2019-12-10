#pragma once

namespace MathAn {
  class Vector3;

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
}
