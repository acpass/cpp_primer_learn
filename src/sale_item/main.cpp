#include <iostream>
#include <string>
#include "sale_item.hpp"

int main()
{
  Sale_item book1, book2;
  std::cout << "input book1: ";
  read(std::cin, book1);
  std::cout << "input book2: ";
  read(std::cin, book2);

  book1.combine(book2);

  print(std::cout, book1);

  return 0;
}