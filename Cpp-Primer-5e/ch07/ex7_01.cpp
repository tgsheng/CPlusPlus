#include <iostream>

struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

int main() {
  Sales_data total;
  if (std::cin >> total.bookNo >> total.units_sold >> total.revenue) {
    Sales_data trans;
    while (std::cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
      if (total.bookNo == trans.bookNo) {
        total.units_sold += trans.units_sold;
        total.revenue += trans.revenue;
      } else {
        std::cout << total.bookNo << ' ' << total.units_sold << ' '
                  << total.revenue << std::endl;
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

/* We cannot directly get a Sales_data object to std::cin using
    std::cin >> total;
  because we haven't overloaded operator>> for Sales_data. We can 
  directly manipulate the members of Sales_data, because the default 
  access level of struct is public. So we assign each member using
    std::cin >> total.bookNo >> total.units_sold >> total.revenue;
*/