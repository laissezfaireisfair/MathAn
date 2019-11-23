#include "./../../include/fraction/Fraction.hpp"
#include "./../../src/fraction/Fraction.cpp"
#include <iostream>
using namespace std;

int main() {
  MathAn::Fraction<int> a(1, 2), b(2, 3);
  cout << "a = " << a.get_str() << "; b = " << b.get_str() << ";" << endl;
  cout << "a + b = " << MathAn::Fraction<int>(a + b).get_str() << ";" << endl;
  cout << "a - b = " << MathAn::Fraction<int>(a - b).get_str() << ";" << endl;
  cout << "a * b = " << MathAn::Fraction<int>(a * b).get_str() << ";" << endl;
  cout << "a / b = " << MathAn::Fraction<int>(a / b).get_str() << ";" << endl;
  cout << "a > b = " << (a > b ? "true" : "false") << ";" << endl;
  cout << "a < b = " << (a < b ? "true" : "false") << ";" << endl;
  cout << "a >= b = " << (a >= b ? "true" : "false") << ";" << endl;
  cout << "a <= b = " << (a <= b ? "true" : "false") << ";" << endl;
  cout << "a == b = " << (a == b ? "true" : "false") << ";" << endl;
  cout << "a != b = " << (a != b ? "true" : "false") << ";" << endl;
  return 0;
}
