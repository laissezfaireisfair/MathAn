#include "./../../../include/geometry.hpp"
#include "./../../../src/geometry.cpp"
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
  print_pnt(a.get_intersection(b), "(a and b intersection)");
  return 0;
}
