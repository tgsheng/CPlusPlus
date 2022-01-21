#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

namespace ch16 {
template <typename Iter, typename Val>
Iter find(Iter first, Iter last, const Val &val) {
  while (first != last && *first != val)
    first++;
  return first;
}
} // namespace ch16

int main() {
  std::vector<int> v{1, 3, 5, 7, 9};
  std::list<std::string> l{"aa", "bb", "cc", "dd"};

  auto iter = ch16::find(v.begin(), v.end(), 2);
  if (iter == v.end())
    std::cout << "Not Found\n";
  else
    std::cout << *iter << '\n';

  auto iter2 = ch16::find(l.begin(), l.end(), "aa");
  if (iter2 == l.end())
    std::cout << "Not Found\n";
  else
    std::cout << *iter2 << '\n';

  return 0;
}