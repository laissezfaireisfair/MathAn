#pragma once
#include "./../include/geometry.hpp"

/// Vector2 functions:
MathAn::Vector2::Vector2() {
  x = 1;
  y = 1;
}
MathAn::Vector2::Vector2(const double xi, const double yi) {
  x = xi;
  y = yi;
}
MathAn::Vector2::Vector2(const MathAn::Vector2 & i) {
  x = i.x;
  y = i.y;
}
double MathAn::Vector2::get_length() const {
  return hypot(x, y);
}
MathAn::Vector2 MathAn::Vector2::get_normalised() const {
  double len = get_length();
  return Vector2(x/len, y/len);
}
MathAn::Vector2 MathAn::Vector2::operator=(const MathAn::Vector2 other){
  x = other.x;
  y = other.y;
  return other;
}
MathAn::Vector2 MathAn::Vector2::operator+(const MathAn::Vector2 other) const {
  return Vector2(x + other.x, y + other.y);
}
MathAn::Vector2 MathAn::Vector2::operator-(const MathAn::Vector2 other) const {
  return Vector2(x - other.x, y - other.y);
}
double MathAn::Vector2::operator*(const MathAn::Vector2 other) const {
  return x * other.x + y * other.y;
}
MathAn::Vector2 MathAn::Vector2::operator+=(const Vector2 other) {
  x += other.x;
  y += other.y;
  return (*this);
}
MathAn::Vector2 MathAn::Vector2::operator-=(const Vector2 other) {
  x -= other.x;
  y -= other.y;
  return (*this);
}
MathAn::Vector2 MathAn::Vector2::operator*=(const double num) {
  x *= num;
  y *= num;
  return (*this);
}
MathAn::Vector2 MathAn::Vector2::operator/=(const double num) {
  x /= num;
  y /= num;
  return (*this);
}
double MathAn::Vector2::get_angle(const MathAn::Vector2 other) const {
  return acos((*this) * other / get_length() / other.get_length());
}
double MathAn::Vector2::get_x() const {
  return x;
}
double MathAn::Vector2::get_y() const {
  return y;
}
bool MathAn::Vector2::operator==(const Vector2 other) const {
  return (x == other.x) && (y == other.y);
}
bool MathAn::Vector2::operator!=(const Vector2 other) const {
  return (x != other.x) || (y != other.y);
}
MathAn::Vector2 MathAn::operator*(const Vector2 vec, const double num) {
  return Vector2(vec.x * num, vec.y * num);
}
MathAn::Vector2 MathAn::operator*(const double num, const Vector2 vec) {
  return Vector2(vec.x * num, vec.y * num);
}
MathAn::Vector2 MathAn::operator/(const Vector2 vec, const double num) {
  return Vector2(vec.x / num, vec.y / num);
}
MathAn::Vector2 MathAn::operator/(const double num, const Vector2 vec) {
  return Vector2(vec.x / num, vec.y / num);
}
bool MathAn::Vector2::is_vector_collinear(const Vector2 other) const {
  return ((*this) * Vector2((-other.y), other.x) == 0);
}
bool MathAn::Vector2::is_vector_normal(const Vector2 other) const {
  return ((*this) * other == 0);
}


/// Point2 functions:
MathAn::Point2::Point2() {
  x = 0;
  y = 0;
}
MathAn::Point2::Point2(double xi, double yi) {
  x = xi;
  y = yi;
}
MathAn::Point2::Point2(const MathAn::Point2 & other) {
  x = other.x;
  y = other.y;
}
double MathAn::Point2::get_x() const {
  return x;
}
double MathAn::Point2::get_y() const {
  return y;
}
double MathAn::Point2::get_dist(const MathAn::Point2 other) const {
  return hypot(other.x - x, other.y - y);
}
MathAn::Vector2 MathAn::Point2::get_movement(const MathAn::Point2 target) const {
  return Vector2(target.x - x, target.y - y);
}
MathAn::Point2 MathAn::Point2::operator=(const MathAn::Point2 other){
  x = other.x;
  y = other.y;
  return other;
}
MathAn::Point2 MathAn::Point2::operator+(const MathAn::Vector2 movement) const {
  return Point2(x + movement.get_x(), y + movement.get_y());
}
MathAn::Point2 MathAn::Point2::operator+=(const MathAn::Vector2 movement) {
  x += movement.get_x();
  y += movement.get_y();
  return *this;
}
bool MathAn::Point2::operator==(const Point2 other) const {
  return (x == other.x) && (y == other.y);
}
bool MathAn::Point2::operator!=(const Point2 other) const {
  return (x != other.x) || (y != other.y);
}


/// Line2 functions:
MathAn::Line2::Line2() {
  a = 1;
  b = 1;
  c = 0;
}
MathAn::Line2::Line2(const double ai, const double bi, const double ci) {
  a = ai;
  b = bi;
  c = ci;
}
MathAn::Line2::Line2(const Line2 & other) {
  a = other.a;
  b = other.b;
  c = other.c;
}
MathAn::Line2::Line2(const Point2 pnt, const Vector2 vec) {
  a = vec.get_y() * (-1.0);
  b = vec.get_x();
  c = vec.get_y() * pnt.get_x() - vec.get_x() * pnt.get_y();
}
MathAn::Line2::Line2(const Point2 p1, const Point2 p2) {
  Vector2 vec(p1.get_movement(p2));
  *this = Line2(p1, vec);
}
MathAn::Line2::Line2(const Point2 pnt, const Line2 prlll) {
  a = prlll.a;
  b = prlll.b;
  c = (-1.0) * prlll.a * pnt.get_x() - prlll.b * pnt.get_y();
}
double MathAn::Line2::get_a() const {
  return a;
}
double MathAn::Line2::get_b() const {
  return b;
}
double MathAn::Line2::get_c() const {
  return c;
}
MathAn::Point2 MathAn::Line2::get_intersection(const Line2 other) const {
  double y = (a * other.c - other.a * c) / (other.a * b - a * other.b);
  double x = (-other.b * y - other.c) / other.a;
  return Point2(x, y);
}
MathAn::Vector2 MathAn::Line2::get_single_direction_vector() const {
  return Vector2(-b, a).get_normalised();
}
MathAn::Vector2 MathAn::Line2::get_single_normal_vector() const {
  return Vector2(a, b).get_normalised();
}
bool MathAn::Line2::is_point_inside(const Point2 pnt) const {
  return (a * pnt.get_x() + b * pnt.get_y() + c == 0);
}
bool MathAn::Line2::is_vector_parallel(const Vector2 vec) const {
  return (vec * get_single_normal_vector() == 0);
}
bool MathAn::Line2::is_vector_normal(const Vector2 vec) const {
  return (vec * get_single_direction_vector() == 0);
}
bool MathAn::Line2::is_line_parallel(const Line2 ln) const {
  return (get_single_normal_vector() * ln.get_single_direction_vector() == 0);
}
bool MathAn::Line2::is_line_normal(const Line2 ln) const {
  return (get_single_normal_vector() * ln.get_single_normal_vector() == 0);
}
MathAn::Line2 MathAn::Line2::operator=(const Line2 other) {
  a = other.a;
  b = other.b;
  c = other.c;
}
bool MathAn::Line2::operator==(const Line2 other) const {
  return ((a / other.a == b / other.b) && (b / other.b == c / other.c));
}
bool MathAn::Line2::operator!=(const Line2 other) const {
  return !(*this == other);
}

/// Circle2 functions:
MathAn::Circle2::Circle2() {
  centre = Point2(0, 0);
  radius = 1;
}
MathAn::Circle2::Circle2(Point2 cntri, double radi) {
  centre = cntri;
  radius = radi;
}
MathAn::Circle2::Circle2(const Circle2 & other) {
  centre = other.centre;
  radius = other.radius;
}
MathAn::Point2 MathAn::Circle2::get_centre() const {
  return centre;
}
double MathAn::Circle2::get_radius() const {
  return radius;
}
MathAn::Circle2 MathAn::Circle2::operator=(const Circle2 other) {
  centre = other.centre;
  radius = other.radius;
}
bool MathAn::Circle2::operator==(const Circle2 other) const {
  return radius == other.radius;
}
bool MathAn::Circle2::operator!=(const Circle2 other) const {
  return radius != other.radius;
}
bool MathAn::Circle2::operator>(const Circle2 other) const {
  return radius > other.radius;
}
bool MathAn::Circle2::operator<(const Circle2 other) const {
  return radius < other.radius;
}
bool MathAn::Circle2::operator>=(const Circle2 other) const {
  return radius >= other.radius;
}
bool MathAn::Circle2::operator<=(const Circle2 other) const {
  return radius <= other.radius;
}
bool MathAn::Circle2::is_inside(const Point2 pnt) const {
  return centre.get_dist(pnt) < radius;
}
bool MathAn::Circle2::is_on_the_border(const Point2 pnt) const {
  return centre.get_dist(pnt) == radius;
}
bool MathAn::Circle2::is_outside(const Point2 pnt) const {
  return centre.get_dist(pnt) > radius;
}
bool MathAn::Circle2::is_match(const Circle2 other) const {
  return (radius == other.radius) && (centre == other.centre);
}
bool MathAn::Circle2::is_cross(const Circle2 other) const {
  return (centre.get_dist(other.centre)) < (radius + other.radius);
}
bool MathAn::Circle2::is_touch(const Circle2 other) const {
  return (centre.get_dist(other.centre)) == (radius + other.radius);
}
MathAn::Circle2 MathAn::Circle2::get_moved(const Vector2 movement) const {
  return Circle2((centre + movement), radius);
}

/// Triangle2 functions:
MathAn::Triangle2::Triangle2() {
  a = Point2(0, 0);
  b = Point2(1, 1);
  c = Point2(2, 0);
}
MathAn::Triangle2::Triangle2(const Point2 ai, const Point2 bi, const Point2 ci) {
  a = ai;
  b = bi;
  c = ci;
}
MathAn::Triangle2::Triangle2(const Line2 ln1, const Line2 ln2, const Line2 ln3) {
  a = ln1.get_intersection(ln2);
  b = ln2.get_intersection(ln3);
  c = ln3.get_intersection(ln1);
}
MathAn::Triangle2::Triangle2(const Triangle2 & other) {
  a = other.a;
  b = other.b;
  c = other.c;
}
MathAn::Point2 MathAn::Triangle2::get_a() const {
  return a;
}
MathAn::Point2 MathAn::Triangle2::get_b() const {
  return b;
}
MathAn::Point2 MathAn::Triangle2::get_c() const {
  return c;
}
MathAn::Triangle2 MathAn::Triangle2::operator=(const Triangle2 other) {
  a = other.a;
  b = other.b;
  c = other.c;
}
bool MathAn::Triangle2::operator==(const Triangle2 other) const{
  if (a.get_movement(b) != other.a.get_movement(other.b))
    return false;
  if (a.get_movement(c) != other.a.get_movement(other.c))
    return false;
  return true;
}
bool MathAn::Triangle2::operator!=(const Triangle2 other) const{
  return !((*this) == other);
}
bool MathAn::Triangle2::is_on_the_border(const Point2 pnt) const {
  if (Line2(a, b).is_point_inside(pnt))
    return true;
  if (Line2(b, c).is_point_inside(pnt))
    return true;
  if (Line2(c, a).is_point_inside(pnt))
    return true;
  return false;
}
MathAn::Triangle2 MathAn::Triangle2::get_moved(const Vector2 movement) const {
  return Triangle2(a + movement, b + movement, c + movement);
}
double MathAn::Triangle2::count_square() const {
  double t1 = a.get_dist(b), t2 = b.get_dist(c), t3 = c.get_dist(a);
  double p = (t1 + t2 + t3) / 2;
  return sqrt(p*(p-t1)*(p-t2)*(p-t3));
}
bool MathAn::Triangle2::is_inside(const Point2 pnt) const {
  Triangle2 t1(a, b, pnt), t2(a, c, pnt), t3(b, c, pnt);
  double s = t1.count_square() + t2.count_square() + t3.count_square();
  return count_square() == s;
}
