#include <memory>

void process(std::shared_ptr<int> ptr) {}

int main() {
  std::shared_ptr<int> p(new int(42));

  /* 12.10: OK */
  process(std::shared_ptr<int>(p));

  /* 12.11: double free */
  process(std::shared_ptr<int>(p.get()));
}