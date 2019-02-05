#include "./../../../include/geometry.hpp"
#include "./../../../src/geometry.cpp"
#include <iostream>
using namespace std;
using namespace MathAn;

void print_pnt(const Point2 & a, const string name) {
  cout << "Point " << name << " (" << a.get_x() << "; ";
  cout << a.get_y() << ");" << endl;
}

void print_vec(const Vector2 & a, const string name) {
  cout << "Vector " << name << " (" << a.get_x() << "; ";
  cout << a.get_y() << ");" << endl;
}

void print_crcl(const Circle2 & a, const string name) {
  cout << "Circle " << name << ":" << endl;
  print_pnt(a.get_centre(), "Centre");
  cout << "Radius = " << a.get_radius() << ";" << endl << endl;
}

void print_truth(const bool flag, const string statement) {
  cout << "(" << statement << ") - ";
  cout << (flag ? "true" : "false") << ";" << endl;
}

int main() {
  Circle2 a, b(Point2(1, 1), 2), c(a);
  print_crcl(a, "a");
  print_crcl(b, "b");
  print_crcl(c, "c");
  c = b;
  cout  << "c = b;" << endl;
  print_crcl(c, "c");
  Point2 pnt(1, 1);
  print_pnt(pnt, "pnt");
  print_truth(a.is_inside(pnt), "pnt is inside a");
  print_truth(a.is_on_the_border(pnt), "pnt is on the border a");
  print_truth(a.is_outside(pnt), "pnt is outside a");
  cout << endl;
  print_truth(a.is_match(c), "a and c is match");
  print_truth(a.is_cross(b), "a is cross b");
  print_truth(a.is_touch(b), "a is touch b");
  cout << endl << "move a + Vector(1, 2)" << endl;
  print_crcl(a.get_moved(Vector2(1, 2)), "Moved a");
  return 0;
}
