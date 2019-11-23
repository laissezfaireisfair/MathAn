#include "./../../../include/geometry2/Vector2.hpp"
#include "./../../../src/geometry2/Vector2.cpp"
#include <iostream>
using namespace std;
using namespace MathAn;

void print_vec(const Vector2 & a, const string name) {
  cout << "Vector " << name << " (" << a.get_x() << "; ";
  cout << a.get_y() << ");" << endl;
}

void print_truth(const bool flag, const string statement) {
  cout << "(" << statement << ") - ";
  cout << (flag ? "true" : "false") << ";" << endl;
}

int main() {
  Vector2 a(1, 2), na(-2, 1), ca(a*3);
  print_vec(a, "a");
  print_vec(a, "na");
  print_vec(a, "ca");
  print_truth(a.is_vector_normal(na), "a is normal to na");
  print_truth(a.is_vector_normal(ca), "a is normal to ca");
  print_truth(a.is_vector_collinear(na), "a is collinear to na");
  print_truth(a.is_vector_collinear(ca), "a is collinear to ca");
  return 0;
}
