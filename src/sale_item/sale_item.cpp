#include <string>
#include <iostream>
#include <stdexcept>
#include "sale_item.hpp"

Sale_item add(const Sale_item &item1, const Sale_item &item2)
{
  Sale_item ret(item1);
  ret.combine(item2);
  return ret;
}

decltype(std::cout) &print(std::ostream &os, const Sale_item &item)
{
  os << item.isbn() << " " << item.unit_sold << " " << item.revenue << " " << item.avg_price();
  return os;
}

decltype(std::cin) &read(std::istream &is, Sale_item &item)
{
  double price = 0;
  is >> item.BookNO >> price >> item.unit_sold;
  while (1)
  {
    try
    {
      if (price < 0)
        throw std::runtime_error("You should input a positive value for price");
      else
        break;
    }
    catch (std::runtime_error err)
    {
      std::cerr << err.what() << std::endl;
      std::cerr << "input price again: ";
      is >> price;
      continue;
    }
  }

  item.revenue = price * item.unit_sold;

  return is;
}