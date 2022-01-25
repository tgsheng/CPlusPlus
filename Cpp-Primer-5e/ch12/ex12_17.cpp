#include <iostream>
#include <memory>

using std::unique_ptr;

int main() {
  int ix = 1024, *pi = &ix, *pi2 = new int(1024);
  typedef unique_ptr<int> IntP;

  // (a) error: no known conversion from 'int' to 'std::unique_ptr<int>'
  // IntP p0(ix);

  // (b) runtime error: when p1 is out of scope, delete will be called to free
  // the object, but the object is not allocated using new
  // IntP p1(pi);

  // (c) Ok, but cause a dangling pointer at run time.
  // IntP p2(pi2);
  
  // (d) the same as (b)
  // IntP p3(&ix);

  // (e) Recommended
  IntP p4(new int(1024));

  // (f) double free
  // IntP p2(pi2);
  // IntP p5(p2.get());
}