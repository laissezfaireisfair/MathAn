#include "./../include/geometry.hpp"
#include "./../src/geometry.cpp"
#include <iostream>
using namespace std;
using namespace MathAn;

int main() {
  Vector2 a, b(1, 2), c(a);
  cout << "a.x = " << a.get_x() << "; a.y = " << a.get_y() << endl;
  cout << "b.x = " << b.get_x() << "; b.y = " << b.get_y() << endl;
  cout << "c.x = " << c.get_x() << "; c.y = " << c.get_y() << endl;
  return 0;
}
