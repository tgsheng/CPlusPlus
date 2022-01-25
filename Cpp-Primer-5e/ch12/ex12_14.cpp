#include <iostream>
#include <memory>

struct destination {};
struct connection {};

connection connect(destination *) {}
void disconnect(connection) {}

void end_connection(connection *c) { disconnect(*c); }

void f(destination &d) {
  connection c = connect(&d);
  std::shared_ptr<connection> p(&c, end_connection);
  /* shared_ptr 假定指向了动态内存，被销毁时，自动调用 delete，这里
   * end_connection 代替 delete，故而自动调用 end_connection 关闭连接 */
}