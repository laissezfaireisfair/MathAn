#include "./../../../include/geometry3.hpp"
#include "./../../../src/geometry3.cpp"
#include <iostream>
using namespace std;

void print_vector(const MathAn::Vector3 & vec) {
  cout << "(" << vec.get_x() << "; " << vec.get_y();
  cout << "; " << vec.get_z() << ")" << endl;
}

int main() {
  MathAn::Vector3 a, b(1, 2, 3), c(a);
  cout << "a";
  print_vector(a);
  cout << "b";
  print_vector(b);
  cout << "c";
  print_vector(c);
  cout << "c = b" << endl;
  c = b;
  cout << "c";
  print_vector(c);
  cout << "c += b" << endl;
  c += b;
  cout << "c";
  print_vector(c);
  cout << "b = a + c" << endl;
  b = a + c;
  cout << "b";
  print_vector(b);
  cout << "b = 3 * c" << endl;
  b = 3 * c;
  cout << "b";
  print_vector(b);
  return 0;
}
