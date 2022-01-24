/* double free or corruption */
#include <memory>

using std::make_shared;

int main() {
  auto sp = make_shared<int>();
  auto p = sp.get();
  delete p;
}