#include <iostream>
#include <thread> // multithreading, -lpthread(linux)

// initial function where the new thread of execution begins
void hello() { std::cout << "Hello Concurrent World\n"; }

int main() {            // the initial thread starts at main()
  std::thread t(hello); // the new thread starts at hello()
  t.join();             /* the calling thread (main) to wait for the thread t
                         * otherwise, main thread may finish and end the program
                         * before the thread t had a chance to run */
}