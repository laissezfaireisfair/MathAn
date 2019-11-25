#include "./../../../include/geometry3/Vector3.hpp"
#include "./../../../src/geometry3/Vector3.cpp"
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
  cout << "a.len = " << a.get_length() << endl;
  cout << "b.len = " << b.get_length() << endl;
  cout << "a.normalised";
  print_vector(a.get_normalised());
  cout << "is a normal to b: " << (a.is_vector_normal(b) ? "y" : "n") << endl;
  cout << "is a collinear to b: ";
  if (a.is_vector_collinear(b))
    cout << "y" << endl;
  else
    cout << "n" << endl;
  cout << "a.get_angle(b) = " << a.get_angle(b) << endl;
  int trash;
  cin >> trash;
  return 0;
}
