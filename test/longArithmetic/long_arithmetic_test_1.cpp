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
  LongNum a(1);
  print_num(a, "a");
  return 0;
}
