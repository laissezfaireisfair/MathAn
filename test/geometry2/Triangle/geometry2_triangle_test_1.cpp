#include "./../../../include/geometry2/Vector2.hpp"
#include "./../../../include/geometry2/Point2.hpp"
#include "./../../../include/geometry2/Line2.hpp"
#include "./../../../include/geometry2/Triangle2.hpp"
#include "./../../../src/geometry2/Vector2.cpp"
#include "./../../../src/geometry2/Point2.cpp"
#include "./../../../src/geometry2/Line2.cpp"
#include "./../../../src/geometry2/Triangle2.cpp"
#include <iostream>
using namespace std;
using namespace MathAn;

void print_pnt(const Point2 & a, const string name) {
  cout << "Point " << name << " (" << a.get_x() << "; ";
  cout << a.get_y() << ");" << endl;
}

void print_truth(const bool flag, const string statement) {
  cout << "(" << statement << ") - ";
  cout << (flag ? "true" : "false") << ";" << endl;
}

void print_trngl(const Triangle2 & a, const string name) {
  cout << "Triangle " << name << ":" << endl;
  print_pnt(a.get_a(), "a");
  print_pnt(a.get_b(), "b");
  print_pnt(a.get_c(), "c");
  cout << endl;
}

int main() {
  Triangle2 a, b(Point2(0,1), Point2(1,0), Point2(3,2)), c(a);
  print_trngl(a, "First");
  print_trngl(b, "Second");
  print_trngl(c, "Third");
  Triangle2 d(Line2(1,-1,0), Line2(1,1,6), Line2(1,0,0));
  print_trngl(d, "Based on lines");
  c = d;
  cout << "Third = Based on lines;" << endl;
  print_trngl(c, "Third");
  print_truth(c==b, "Third == Second");
  print_truth(c!=a, "Third != First");
  cout << endl;
  Point2 pnt(1,0);
  print_pnt(pnt, "pnt");
  print_truth(a.is_inside(pnt), "pnt is inside First");
  print_truth(a.is_on_the_border(pnt), "pnt is on the border First");
  print_trngl(a.get_moved(Vector2(1, 1)), "First moved + (1,1)");
  cout << "First square = " << a.count_square() << ";" << endl;
  int trash;
  cin >> trash;
  return 0;
}
