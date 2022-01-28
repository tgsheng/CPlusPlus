#include <thread>

class thread_guard {
  std::thread &t;

public:
  explicit thread_guard(std::thread &t_) : t(t_) {}
  ~thread_guard() {
    if (t.joinable()) // join() can be called only once for a given thread
      t.join();
  }
  thread_guard(const thread_guard &) = delete;
  thread_guard &operator=(const thread_guard &) = delete;
};

void do_something(int &i) { ++i; }

struct func {
  int &i;
  func(int &i_) : i(i_) {}
  void operator()() {
    for (unsigned j = 0; j < 1000000; ++j)
      do_something(i); // potential access to dangling reference
  }
};

void do_something_in_current_thread() {}

void f() {
  int some_local_state = 0;
  func my_func(some_local_state);
  std::thread t(my_func);
  thread_guard g(t);

  do_something_in_current_thread();
} // When the execution of the current thread reaches the end of f, the local
  // objects are destroyed in reverse order of construction. Consequently, the
  // thread_guard object, g, is destroyed first, and the thread is joined with,
  // in the destructor. This even happens if the function exits because
  // do_something_in_current_thread throws an exception.

int main() { f(); }