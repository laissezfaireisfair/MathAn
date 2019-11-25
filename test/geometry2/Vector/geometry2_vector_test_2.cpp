#include "./../../../include/geometry2/Vector2.hpp"
#include "./../../../src/geometry2/Vector2.cpp"
#include <iostream>
using namespace std;
using namespace MathAn;

int main() {
  Vector2 a(1, 2);
  cout << "a = (" << a.get_x() << "; " << a.get_y() << ");" << endl;
  cout << "3*a = (" << (3*a).get_x() << "; " << (3*a).get_y() << ");" << endl;
  cout << "a*3 = (" << (a*3).get_x() << "; " << (a*3).get_y() << ");" << endl;
  cout << "3/a = (" << (3/a).get_x() << "; " << (3/a).get_y() << ");" << endl;
  cout << "a/3 = (" << (a/3).get_x() << "; " << (a/3).get_y() << ");" << endl;
  int trash;
  cin >> trash;
  return 0;
}
