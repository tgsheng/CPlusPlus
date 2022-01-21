#include "../ch07/ex7_06.h" // struct Sales_data
#include <iostream>
#include <vector>

template <typename T> int compare(const T &lhs, const T &rhs) {
  if (lhs < rhs) return -1;
  if (rhs < lhs) return 1;
  return 0;
}

int main() {
  std::cout << compare(2, 5) << std::endl;

  std::vector<int> v1{1, 2, 3}, v2{2, 3, 4}; // 支持 operator<
  std::cout << compare(v1, v2) << std::endl;

  Sales_data trans1, trans2;
  // compare(trans1, trans2); // error: invalid operands to binary expression
  // ('const Sales_data' and 'const Sales_data')
}