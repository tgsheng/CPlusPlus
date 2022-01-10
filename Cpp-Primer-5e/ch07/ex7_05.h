#ifndef CP5_ex7_05_H
#define CP5_ex7_05_H

#include <string>

class Person {
public:
  std::string get_name() const { return name; }
  std::string get_addr() const { return address; }

private:
  std::string name;
  std::string address;
};

#endif /* CP5_ex7_05_H */