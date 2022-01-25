#include <iostream>
#include <memory>

struct destination {
  std::string ip;
  int port;
  destination(std::string _ip, int _port) : ip(_ip), port(_port) {}
};
struct connection {
  std::string ip;
  int port;
  connection(std::string _ip, int _port) : ip(_ip), port(_port) {}
};

connection connect(destination *pDest) {
  std::shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
  std::cout << "creating connection(" << pConn.use_count() << ")" << std::endl;
  return *pConn;
}
void disconnect(connection conn) {
  std::cout << "connection close(" << conn.ip << ":" << conn.port << ")"
            << std::endl;
}

void end_connection(connection *pConn) { disconnect(*pConn); }

void f(destination &dest) {
  connection conn = connect(&dest);
  std::shared_ptr<connection> p(&conn, end_connection);
  /* shared_ptr 假定指向了动态内存，被销毁时，自动调用 delete，这里
   * end_connection 代替 delete，故而自动调用 end_connection 关闭连接 */
  std::cout << "connection now(" << p.use_count() << ")" << std::endl;
}

int main() {
  destination dest("127.0.0.1", 1234);
  f(dest);

  return 0;
}