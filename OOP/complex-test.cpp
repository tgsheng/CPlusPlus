#include "complex.h"

int main() {
  complex<double> c1(2.0, 3.0);
  complex<int> c2(c1);

  std::cout << c1 << '\n';
  std::cout << c2 << '\n';
  std::cout << c1 + 7.0 << '\n';
  std::cout << c1 + c1 << '\n';
  std::cout << c2 + 7 << '\n';
  std::cout << c2 + c2 << '\n';

  c1 += c2;
  c1 -= 7;
  std::cout << c1 << '\n';

  return 0;
}