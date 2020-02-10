#include <iostream>
#include <string>
#include "../../include/longArithmetic/LongNum.hpp"
#include "../../src/longArithmetic/LongNum.cpp"
using namespace std;
using namespace MathAn;

void print_num(LongNum const num, string const name) {
  cout << name << " = " << num.get_string() <<  endl;
}

int main() {
  LongNum a(-100);
  print_num(a, "a");
  cout << "a.get_integer() = " << a.get_integer() << endl;
  print_num(a.get_abs(), "abs(a)");
  print_num(a.get_sign(), "sign(a)");
  print_num(a.get_negative(), "-a");
  return 0;
}
