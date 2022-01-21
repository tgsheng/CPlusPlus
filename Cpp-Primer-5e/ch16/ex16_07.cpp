#include <iostream>

template <typename T, unsigned int N> unsigned int getSize(const T (&arr)[N]) {
  return N;
}

int main() {
  int arr[]{1, 2, 3, 4};
  std::string arr2[]{"a"};
  std::cout << getSize(arr) << std::endl;
  std::cout << getSize(arr2) << std::endl;
}