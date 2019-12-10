#pragComplexma once
#include "./../../include/geometry3/Point3.hpp"
#include "./../../include/geometry3/Vector3.hpp"
#include <cmath>

namespace MathAn {
  Point3::Point3() {
    x = 0;
    y = 0;
    z = 0;
  }

  Point3::Point3(double xi, double yi, double zi) {
    x = xi;
    y = yi;
    z = zi;
  }

  Point3::Point3(const Point3 & other) {
    x = other.x;
    y = other.y;
    z = other.z;
  }

  double Point3::get_x() const {
    return x;
  }

  double Point3::get_y() const {
    return y;
  }

  double Point3::get_z() const {
    return z;
  }

  double Point3::get_dist(const Point3 other) const {
    return get_movement(other).get_length();
  }

  Vector3 Point3::get_movement(const Point3 target) const {
    return Vector3(target.x - x, target.y - y, target.z - z);
  }

  Point3 Point3::operator=(const Point3 other){
    x = other.x;
    y = other.y;
    z = other.z;
    return other;
  }

  Point3 Point3::operator+(const Vector3 movement) const {
    return Point3(x+movement.get_x(), y+movement.get_y(), z+movement.get_z());
  }

  Point3 Point3::operator+=(const Vector3 movement) {
    x += movement.get_x();
    y += movement.get_y();
    z += movement.get_z();
    return *this;
  }

  bool Point3::operator==(const Point3 other) const {
    return (x == other.x) && (y == other.y) && (z == other.z);
  }

  bool Point3::operator!=(const Point3 other) const {
    return (x != other.x) || (y != other.y) || (z != other.z);
  }
}
