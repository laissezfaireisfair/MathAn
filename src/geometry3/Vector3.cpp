#pragma once
#include "./../../include/geometry3/Vector3.hpp"

MathAn::Vector3::Vector3() {
  x = 1;
  y = 1;
  z = 1;
}

MathAn::Vector3::Vector3(const double xi, const double yi, const double zi) {
  x = xi;
  y = yi;
  z = zi;
}

MathAn::Vector3::Vector3(const MathAn::Vector3 & i) {
  x = i.x;
  y = i.y;
  z = i.z;
}

double MathAn::Vector3::get_length() const {
  return sqrt(x * x + y * y + z * z);
}

MathAn::Vector3 MathAn::Vector3::get_normalised() const {
  double len = get_length();
  return Vector3(x/len, y/len, z/len);
}

MathAn::Vector3 MathAn::Vector3::operator=(const MathAn::Vector3 other){
  x = other.x;
  y = other.y;
  z = other.z;
  return other;
}

MathAn::Vector3 MathAn::Vector3::operator+(const MathAn::Vector3 other) const {
  return Vector3(x + other.x, y + other.y, z + other.z);
}

MathAn::Vector3 MathAn::Vector3::operator-(const MathAn::Vector3 other) const {
  return Vector3(x - other.x, y - other.y, z - other.z);
}

double MathAn::Vector3::operator*(const MathAn::Vector3 other) const {
  return x * other.x + y * other.y + z * other.z;
}

MathAn::Vector3 MathAn::Vector3::operator+=(const Vector3 other) {
  x += other.x;
  y += other.y;
  z += other.z;
  return (*this);
}

MathAn::Vector3 MathAn::Vector3::operator-=(const Vector3 other) {
  x -= other.x;
  y -= other.y;
  z -= other.z;
  return (*this);
}

MathAn::Vector3 MathAn::Vector3::operator*=(const double num) {
  x *= num;
  y *= num;
  z *= num;
  return (*this);
}

MathAn::Vector3 MathAn::Vector3::operator/=(const double num) {
  x /= num;
  y /= num;
  z /= num;
  return (*this);
}

double MathAn::Vector3::get_angle(const MathAn::Vector3 other) const {
  return acos((*this) * other / get_length() / other.get_length());
}

double MathAn::Vector3::get_x() const {
  return x;
}

double MathAn::Vector3::get_y() const {
  return y;
}

double MathAn::Vector3::get_z() const {
  return z;
}

bool MathAn::Vector3::operator==(const Vector3 other) const {
  return (x == other.x) && (y == other.y) && (z == other.z);
}

bool MathAn::Vector3::operator!=(const Vector3 other) const {
  return (x != other.x) || (y != other.y) || (z != other.z);
}

MathAn::Vector3 MathAn::operator*(const Vector3 vec, const double num) {
  return Vector3(vec.x * num, vec.y * num, vec.z * num);
}

MathAn::Vector3 MathAn::operator*(const double num, const Vector3 vec) {
  return Vector3(vec.x * num, vec.y * num, vec.z * num);
}

MathAn::Vector3 MathAn::operator/(const Vector3 vec, const double num) {
  return Vector3(vec.x / num, vec.y / num, vec.z / num);
}

MathAn::Vector3 MathAn::operator/(const double num, const Vector3 vec) {
  return Vector3(vec.x / num, vec.y / num, vec.z / num);
}

bool MathAn::Vector3::is_vector_collinear(const Vector3 other) const {
  return (x / other.x == y / other.y == z / other.z);
}

bool MathAn::Vector3::is_vector_normal(const Vector3 other) const {
  return ((*this) * other == 0);
}
