#include <iostream>
#include <memory>

using std::unique_ptr;

int main() {
  unique_ptr<int> p1(new int(42));
  /* Call to deleted constructor of 'unique_ptr<int>'clang(ovl_deleted_init)
   * unique_ptr.h(468, 7): 'unique_ptr' has been explicitly marked deleted here
   */
  unique_ptr<int> p2 = p1;
  unique_ptr<int> p3(p1);

  unique_ptr<int> p4;
  /* Overload resolution selected deleted operator '='clang(ovl_deleted_oper)
   * unique_ptr.h(469, 19): Candidate function has been explicitly deleted */
  p4 = p1;

  // unique_ptr 在实现的时候，将拷贝构造和拷贝复制函数定义为 delete
}