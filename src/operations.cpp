#include "./../include/operations.hpp"
using namespace MathAn;

template<class Num> Num MathAn::Operations::gcd(const Num a, const Num b){
  if (b == 0)
		return a;
	return Operations::gcd(b, a % b);
}
