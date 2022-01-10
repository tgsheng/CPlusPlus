#include <iostream>

struct Sales_data { // the default access level is public
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

int main() {
  Sales_data total;
  if (std::cin >> total.bookNo >> total.units_sold >>
      total.revenue) { // we don't overload operator>> for Sales_data
    Sales_data trans;
    while (std::cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
      if (total.bookNo == trans.bookNo) {
        total.units_sold += trans.units_sold;
        total.revenue += trans.revenue;
      } else {
        std::cout << total.bookNo << ' ' << total.units_sold << ' '
                  << total.revenue
                  << std::endl; // we don't overload operator<< for Sales_data
        total = trans;
      }
    }
    std::cout << total.bookNo << ' ' << total.units_sold << ' ' << total.revenue
              << std::endl;
  } else {
    std::cerr << "No data?!" << std::endl;
    return -1;
  }
  return 0;
}