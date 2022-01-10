#ifndef CP5_ex7_05_H
#define CP5_ex7_05_H

#include <iostream>
#include <string>

struct Person {
  std::string get_name() const { return name; }
  std::string get_addr() const { return address; }

  std::string name;
  std::string address;
};

inline std::istream &read(std::istream &is, Person &person) {
  return is >> person.name >> person.address;
}

inline std::ostream &print(std::ostream &os, const Person &person) {
  return os << person.get_name() << " " << person.get_addr();
}

#endif /* CP5_ex7_05_H */