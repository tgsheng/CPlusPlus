#include <thread>

void do_something(int &i) { ++i; }

struct func {
  int &i;
  func(int &i_) : i(i_) {}
  void operator()() {
    for (unsigned j = 0; j < 1000000; ++j)
      do_something(i); // Potential access to dangling reference
  }
};

void do_something_in_current_thread() {}

void f() {
  int some_local_state = 0;
  func my_func(some_local_state);
  std::thread t(my_func);
  try {
    do_something_in_current_thread();
  } catch (...) {
    t.join(); // Using try/catch block to ensure that a thread with access to
    throw;    // local state is finished before the function exists, whether
  }           // the function exits by an exception
  t.join();   // or normally
} // This isn't an ideal scenario, see listing_2.3.cpp

int main() { f(); }
