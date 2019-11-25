#include "./../../../include/geometry2/Line2.hpp"
#include "./../../../src/geometry2/Line2.cpp"
#include <iostream>
#include <cstring>
using namespace std;
using namespace MathAn;

void print_line(const Line2 & a, const string name) {
  cout << "Line " << name << ": " << a.get_a() << "*x + ";
  cout << a.get_b() << "*y + " << a.get_c() << " = 0;" << endl;
}

void print_pnt(const Point2 & a, const string name) {
  cout << "Point " << name << " (" << a.get_x() << "; ";
  cout << a.get_y() << ");" << endl;
}

void print_vec(const Vector2 & a, const string name) {
  cout << "Vector " << name << " (" << a.get_x() << "; ";
  cout << a.get_y() << ");" << endl;
}

int main() {
  Line2 a, b(1, 2, -3), c(a);
  print_line(a, "A");
  print_line(b, "B");
  print_line(c, "C");
  Point2 pnt = a.get_intersection(b);
  cout << "pnt = a and b intersection;" << endl;
  print_pnt(pnt, "pnt");
  Vector2 dir = b.get_single_direction_vector();
  cout << "direction = b.get_single_direction_vector();" << endl;
  print_vec(dir, "direction");
  Vector2 nrml = b.get_single_normal_vector();
  cout << "normal = b.get_single_normal_vector();" << endl;
  print_vec(nrml, "normal");
  cout << "Is pnt inside B-" << (b.is_point_inside(pnt) ? "Yes;" : "No;") << endl;
  cout << "Is dir parall B-" << (b.is_vector_parallel(dir) ? "Yes;" : "No;") << endl;
  cout << "Is a parall B-" << (b.is_line_parallel(a) ? "Yes;" : "No;") << endl;
  cout << "Is nrml normal B-" << (b.is_vector_normal(nrml) ? "Yes;" : "No;") << endl;
  cout << "Is a normal B-" << (b.is_line_normal(a) ? "Yes;" : "No;") << endl;
  c = b;
  cout << "c = b;" << endl;
  print_line(c, "C");
  cout << "A != B " << (a != b ? "Yes;" : "No;") << endl;
  cout << "A == C " << (a == c ? "Yes;" : "No;") << endl;
  int trash;
  cin >> trash;
  return 0;
}
