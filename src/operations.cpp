#include "./../include/operations.hpp"
using namespace MathAn;

static template<class Num> Num Operations::gcd(const Num a, const Num b) {
  if (b == 0)
		return a;
	return Operations::gcd(b, a % b);
}
