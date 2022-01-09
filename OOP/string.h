#pragma once

#include <cstring>
#include <iostream>

class string {
public:
  string(const char *cstr = nullptr);
  string(unsigned int n, char c);

  string(const string &);
  string(string &&str) : _data(str._data) { str._data = nullptr; }

  string &operator=(const string &);
  string operator=(string &&);

  ~string();

  constexpr char *data() const { return _data; }
  unsigned int size() const { return strlen(_data); }
  bool empty() const { return size() == 0; }

  const char &operator[](int pos) const { return data()[pos]; }
  // char &operator[](int pos) { return data()[pos]; }
  char &operator[](int pos) {
    return const_cast<char &>(static_cast<const string &>(*this)[pos]);
  }

private:
  char *_data;
};

inline string::string(const char *cstr) {
  if (cstr) {
    _data = new char[sizeof cstr];
    strcpy(_data, cstr);
  } else {
    _data = new char[1];
    *_data = '\0';
  }
}

inline string::string(unsigned int n, char c) {
  _data = new char[n + 1];
  for (int i = 0; i < n; i++)
    _data[i] = c;
  _data[n] = '\0';
}

inline string::string(const string &str) {
  _data = new char[sizeof str._data];
  strcpy(_data, str._data);
}

inline string &string::operator=(const string &str) {
  if (this != &str) {
    delete[] _data;
    _data = new char[sizeof(str._data)];
    strcpy(_data, str._data);
  }
  return *this;
}

inline string string::operator=(string &&str) {
  if (this != &str) {
    delete[] _data;
    _data = str._data;
    str._data = nullptr;
  }
  return *this;
}

inline string::~string() { delete[] _data; }

inline string operator+(const string &lhs, const string &rhs) {
  char *newData = new char[lhs.size() + rhs.size() + 1];
  strcpy(newData, lhs.data());
  strcat(newData, rhs.data());
  string r(newData);
  return r;
}

inline string operator+(const string &lhs, const char *rhs) {
  // char *newData = new char[lhs.size() + sizeof rhs];
  // strcpy(newData, lhs.data());
  // strcat(newData, rhs);
  // string r(newData);
  // return r;
  string str(rhs);
  return lhs + str;
}

inline string operator+(const char *lhs, const string &rhs) {
  // char *newData = new char[sizeof lhs + rhs.size()];
  // strcpy(newData, lhs);
  // strcat(newData, rhs.data());
  // string r(newData);
  // return r;
  string str(lhs);
  return str + rhs;
}

inline std::ostream &operator<<(std::ostream &os, const string &str) {
  return os << str.data();
}