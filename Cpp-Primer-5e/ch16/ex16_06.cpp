#include <iostream>
#include <string>

template <typename T, unsigned int N> T *begin(const T (&arr)[N]) {
  return arr;
}

template <typename T, unsigned int N> T *end(const T (&arr)[N]) {
  return arr + N;
}

int main() {
  std::string strArr[]{"a", "b", "c", "d", "e"};
  std::cout << *begin(strArr) << std::endl;
  std::cout << *(end(strArr) - 1) << std::endl;
  return 0;
}