#ifndef CP5_ex7_06_H
#define CP5_ex7_06_H

#include <iostream>
#include <string>

struct Sales_data {
  std::string const &isbn() const { return bookNo; };
  Sales_data &combine(const Sales_data &);

  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

inline Sales_data &Sales_data::combine(const Sales_data &rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

inline std::istream &read(std::istream &is, Sales_data &item) {
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}

inline std::ostream &print(std::ostream &os, const Sales_data &item) {
  os << item.isbn() << " " << item.units_sold << " " << item.revenue;
  return os;
}

inline Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;
  sum.combine(rhs);
  return sum;
}

#endif /* CP5_ex7_06_H */