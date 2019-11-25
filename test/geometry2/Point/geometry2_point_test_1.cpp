#include "./../../../include/geometry.hpp"
#include "./../../../src/geometry.cpp"
#include <iostream>
using namespace std;
using namespace MathAn;

int main() {
  Point2 a, b(1, 2), c(a);
  cout << "a.x = " << a.get_x() << "; a.y = " << a.get_y() << ";" << endl;
  cout << "b.x = " << b.get_x() << "; b.y = " << b.get_y() << ";" << endl;
  cout << "c.x = " << c.get_x() << "; c.y = " << c.get_y() << ";" << endl;
  cout << "dist(a, b) = " << a.get_dist(b) << ";" << endl;
  c = a;
  cout << "c = a;" << endl;
  cout << "c.x = " << c.get_x() << "; c.y = " << c.get_y() << ";" << endl;
  Vector2 movAB = a.get_movement(b);
  cout << "movement(a, b).x = " << movAB.get_x();
  cout << "; movement(a, b).y = " << movAB.get_y() << ";" << endl;
  c += movAB;
  cout << "c += movAB;" << endl;
  cout << "c.x = " << c.get_x() << "; c.y = " << c.get_y() << ";" << endl;
  a = a + movAB;
  cout << "a = a + movAB;" << endl;
  cout << "a.x = " << a.get_x() << "; a.y = " << a.get_y() << ";" << endl;
  b = Point2(0, 0);
  cout << "b = (0;0);" << endl;
  cout << "A == B = " << (a == b ? "true" : "false") << ";" << endl;
  cout << "A != B = " << (a != b ? "true" : "false") << ";" << endl;
  int trash;
  cin >> trash;
  return 0;
}
