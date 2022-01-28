#include <thread>

void do_something(int &i) { ++i; }

struct func {
  int &i;
  func(int &i_) : i(i_) {} // The way to initialized a reference member
  void operator()() {
    for (unsigned j = 0; j < 1000000; j++)
      do_something(i); // Potential access to dangling reference
  }
};

void oops() {
  int some_local_state = 0;
  func my_func(some_local_state);
  std::thread my_thread(my_func); // std::thread works with any callable type
  my_thread.detach();             // Don't wait for thread to finish
} // New thread might still be running, and do_something() will access an
  // already destroyed variable
  // Using my_thread.join() to wait for my_thread to complete, see
  // listing_2.2.cpp and listing_2.3.cpp

int main() { oops(); }