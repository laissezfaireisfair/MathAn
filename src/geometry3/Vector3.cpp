#pragma once
#include "./../../include/geometry3/Vector3.hpp"
#include <cmath>

namespace MathAn {
  Vector3::Vector3() {
    x = 1;
    y = 1;
    z = 1;
  }

  Vector3::Vector3(const double xi, const double yi, const double zi) {
    x = xi;
    y = yi;
    z = zi;
  }

  Vector3::Vector3(const Vector3 & i) {
    x = i.x;
    y = i.y;
    z = i.z;
  }

  double Vector3::get_length() const {
    return sqrt(x * x + y * y + z * z);
  }

  Vector3 Vector3::get_normalised() const {
    double len = get_length();
    return Vector3(x/len, y/len, z/len);
  }

  Vector3 Vector3::operator=(const Vector3 other){
    x = other.x;
    y = other.y;
    z = other.z;
    return other;
  }

  Vector3 Vector3::operator+(const Vector3 other) const {
    return Vector3(x + other.x, y + other.y, z + other.z);
  }

  Vector3 Vector3::operator-(const Vector3 other) const {
    return Vector3(x - other.x, y - other.y, z - other.z);
  }

  double Vector3::operator*(const Vector3 other) const {
    return x * other.x + y * other.y + z * other.z;
  }

  Vector3 Vector3::operator+=(const Vector3 other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return (*this);
  }

  Vector3 Vector3::operator-=(const Vector3 other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return (*this);
  }

  Vector3 Vector3::operator*=(const double num) {
    x *= num;
    y *= num;
    z *= num;
    return (*this);
  }

  Vector3 Vector3::operator/=(const double num) {
    x /= num;
    y /= num;
    z /= num;
    return (*this);
  }

  double Vector3::get_angle(const Vector3 other) const {
    return acos((*this) * other / get_length() / other.get_length());
  }

  double Vector3::get_x() const {
    return x;
  }

  double Vector3::get_y() const {
    return y;
  }

  double Vector3::get_z() const {
    return z;
  }

  bool Vector3::operator==(const Vector3 other) const {
    return (x == other.x) && (y == other.y) && (z == other.z);
  }

  bool Vector3::operator!=(const Vector3 other) const {
    return (x != other.x) || (y != other.y) || (z != other.z);
  }

  Vector3 operator*(const Vector3 vec, const double num) {
    return Vector3(vec.x * num, vec.y * num, vec.z * num);
  }

  Vector3 operator*(const double num, const Vector3 vec) {
    return Vector3(vec.x * num, vec.y * num, vec.z * num);
  }

  Vector3 operator/(const Vector3 vec, const double num) {
    return Vector3(vec.x / num, vec.y / num, vec.z / num);
  }

  Vector3 operator/(const double num, const Vector3 vec) {
    return Vector3(vec.x / num, vec.y / num, vec.z / num);
  }

  bool Vector3::is_vector_collinear(const Vector3 other) const {
    return (x / other.x == y / other.y == z / other.z);
  }

  bool Vector3::is_vector_normal(const Vector3 other) const {
    return ((*this) * other == 0);
  }
}
