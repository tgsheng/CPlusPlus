#include <memory>

void process(std::shared_ptr<int> ptr) {}

int main() {
  auto p = new int();
  auto sp = std::make_shared<int>();

  // (a) Ok.
  process(sp);

  // (b) Error: no known conversion from 'int *' to 'std::shared_ptr<int>'.
  // process(new int());

  // (c) Error: no known conversion from 'int *' to 'std::shared_ptr<int>'.
  // process(p);

  // (d) Ok. But it's a bad practice to do so.
  process(std::shared_ptr<int>(p));
  /* Because using smart pointer together with raw pointer could potentially
   * cause problems. If we delete the pointer p unintentionally, it will cause
   * the runtime error -- double free or corruption  */
  // delete p;
}