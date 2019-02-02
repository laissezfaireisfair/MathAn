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
  c = a + b;
  cout << "a = a + b;" << endl;
  cout << "c.x = " << c.get_x() << "; c.y = " << c.get_y() << endl;
  c = a - b;
  cout << "a = a - b;" << endl;
  cout << "c.x = " << c.get_x() << "; c.y = " << c.get_y() << endl;
  cout << "b.length = " << b.get_length() << ";" << endl;
  c = b.get_normalised();
  cout << "c = normalise(b);" << endl;
  cout << "c.x = " << c.get_x() << "; c.y = " << c.get_y() << endl;
  cout << "angle(a, b) = " << a.get_angle(b) << ";" << endl;
  return 0;
}
