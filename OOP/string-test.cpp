#include "string.h"

int main() {
  string s1("Hello");
  string s2;
  std::cout << "s1.size(): " << s1.size() << '\n';
  std::cout << "s1.data(): " << s1.data() << '\n';
  std::cout << "s2.size(): " << s2.size() << '\n';
  std::cout << "s2.data(): " << s2.data() << '\n';

  s2 = s1;
  std::cout << "s2.size(): " << s2.size() << '\n';
  std::cout << "s2.data(): " << s2.data() << '\n';

  string s3(s1);
  std::cout << "s3.size(): " << s3.size() << '\n';
  std::cout << "s3.data(): " << s3.data() << '\n';
  s3[0] = 'h';
  std::cout << "s3.size(): " << s3.size() << '\n';
  std::cout << "s3.data(): " << s3.data() << '\n';

  const string s4("const-string");
  std::cout << "s4.size(): " << s4.size() << '\n';
  std::cout << "s4.data(): " << s4.data() << '\n';
  // s4[0] = 'h';
  std::cout << "s4[0]: " << s4[0] << '\n';

  string s5(std::move(s1));
  std::cout << "s5.size(): " << s5.size() << '\n';
  std::cout << "s5.data(): " << s5.data() << '\n';
  // std::cout << "s1.size(): " << s1.size() << '\n';
  // std::cout << "s1.data(): " << s1.data() << '\n';

  string s("World");
  s5 = std::move(s);
  std::cout << "s5.size(): " << s5.size() << '\n';
  std::cout << "s5.data(): " << s5.data() << '\n';
  // std::cout << "s.size(): " << s.size() << '\n';
  // std::cout << "s.data(): " << s.data() << '\n';

  string s6(3, 'c');
  std::cout << "s6.size(): " << s6.size() << '\n';
  std::cout << "s6.data(): " << s6.data() << '\n';

  std::cout <<  s2 + " " + s5  << '\n';

  return 0;
}