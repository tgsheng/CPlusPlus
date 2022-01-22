#include <iostream>
#include <vector>

using Ptr = std::vector<int> *;

auto make() { return new std::vector<int>{}; }

auto populate(Ptr vec) {
  int i;
  while (std::cin >> i)
    vec->push_back(i);
  return vec;
}

auto &print(Ptr vec) {
  for (auto i : *vec)
    std::cout << i << ' ';
  return std::cout;
}

int main() {
  auto vec = populate(make());
  print(vec) << std::endl;
  delete vec;

  return 0;
}