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
  LongNum a(-100), b = 101;
  print_num(a, "a");
  print_num(b, "b");
  print_num(a + b, "a + b");
  print_num(a - b, "a - b");
  print_num(a * b, "a * b");
  print_num(a / b, "a / b");
  return 0;
}
