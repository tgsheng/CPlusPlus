#include <iostream>
#include <string>

/* Solution 1 */
/*
template <typename T, unsigned int N> void print(const T (&arr)[N]) {
  for (int i = 0; i < N; i++)
    std::cout << arr[i] << ' ';
  std::cout << std::endl;
}
*/

/* Solution 2 */
template <typename Array> void print(const Array &arr) {
  for (auto &elem : arr)
    std::cout << elem << ' ';
  std::cout << std::endl;
}

int main() {
  int arr[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  print(arr);
  std::string strArr[5]{"a", "b", "c", "d", "e"};
  print(strArr);
}