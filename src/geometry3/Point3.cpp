#pragma once
#include "./../../include/geometry3/Point3.hpp"

MathAn::Point3::Point3() {
  x = 0;
  y = 0;
  z = 0;
}

MathAn::Point3::Point3(double xi, double yi, double zi) {
  x = xi;
  y = yi;
  z = zi;
}

MathAn::Point3::Point3(const MathAn::Point3 & other) {
  x = other.x;
  y = other.y;
  z = other.z;
}

double MathAn::Point3::get_x() const {
  return x;
}

double MathAn::Point3::get_y() const {
  return y;
}

double MathAn::Point3::get_z() const {
  return z;
}

double MathAn::Point3::get_dist(const MathAn::Point3 other) const {
  return get_movement(other).get_length();
}

MathAn::Vector3 MathAn::Point3::get_movement(const MathAn::Point3 target) const {
  return Vector3(target.x - x, target.y - y, target.z - z);
}

MathAn::Point3 MathAn::Point3::operator=(const MathAn::Point3 other){
  x = other.x;
  y = other.y;
  z = other.z;
  return other;
}

MathAn::Point3 MathAn::Point3::operator+(const MathAn::Vector3 movement) const {
  return Point3(x+movement.get_x(), y+movement.get_y(), z+movement.get_z());
}

MathAn::Point3 MathAn::Point3::operator+=(const MathAn::Vector3 movement) {
  x += movement.get_x();
  y += movement.get_y();
  z += movement.get_z();
  return *this;
}

bool MathAn::Point3::operator==(const Point3 other) const {
  return (x == other.x) && (y == other.y) && (z == other.z);
}

bool MathAn::Point3::operator!=(const Point3 other) const {
  return (x != other.x) || (y != other.y) || (z != other.z);
}
