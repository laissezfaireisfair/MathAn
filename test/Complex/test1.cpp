#include "./../../include/complex.hpp"
#include "./../../src/complex.cpp"
#include <iostream>
using namespace std;
using namespace MathAn;

void print_cmplx(const Complex & num, const string name) {
  cout << name << " = " << num.get_a();
  cout << " + i*(" << num.get_b() << ");" << endl;
}

int main() {
  Complex a, b(1, 2), c(3), d(a);
  print_cmplx(a, "a");
  print_cmplx(b, "b");
  print_cmplx(c, "c");
  print_cmplx(d, "d");
  cout << "d = b;" << endl;
  d = b;
  print_cmplx(d, "d");
  cout << endl;
  print_cmplx(a + b, "a + b");
  print_cmplx(a - b, "a - b");
  print_cmplx(a * b, "a * b");
  print_cmplx(a / b, "a / b");
  cout << endl;
  print_cmplx(a.get_conjugate(), "conjugate a");
  cout << "abs(a) = " << a.get_abs() << ";" << endl;
  cout << "arg(a) = " << a.get_arg() << ";" << endl;
  cout << endl;
  cout << "a += b;" << endl;
  a += b;
  print_cmplx(a, "a");
  cout << endl;
  cout << "a -= b;" << endl;
  a -= b;
  print_cmplx(a, "a");
  cout << endl;
  cout << "a *= b;" << endl;
  a *= b;
  print_cmplx(a, "a");
  cout << endl;
  cout << "a /= b;" << endl;
  a /= b;
  print_cmplx(a, "a");
  return 0;
}
