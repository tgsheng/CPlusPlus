#include <iostream>
#include <memory>
#include <vector>

using SPtr = std::shared_ptr<std::vector<int>>;

auto make() { return std::make_shared<std::vector<int>>(); }

auto populate(SPtr vec) {
  int i;
  while (std::cin >> i)
    vec->push_back(i);
  return vec;
}

auto &print(SPtr vec) {
  for (auto i : *vec)
    std::cout << i << ' ';
  return std::cout;
}

int main() {
  auto vec = populate(make());
  print(vec) << std::endl;

  return 0;
}