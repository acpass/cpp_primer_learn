#include <iostream>

int main() {
  int val;
  std::cin >> val;
  std::cout << std::cin.good() << '\n';
  std::cout << std::cin.fail() << '\n';
  std::cout << std::cin.bad() << '\n';
  std::cout << std::cin.eof() << '\n';
  std::cout << std::cin.rdstate() << '\n';
  std::cout << std::endl;

  std::cin.setstate(std::istream::badbit | std::istream::failbit |
                    std::istream::eofbit);
  std::cout << std::cin.rdstate() << '\n';
  std::cout << std::cin.good() << '\n';
  std::cout << std::cin.fail() << '\n';
  std::cout << std::cin.bad() << '\n';
  std::cout << std::cin.eof() << '\n';
  std::cout << std::endl;

  std::cin.clear(
      std::cin.rdstate() &
      ~std::istream::eofbit); // the parameter mean the final state of cin
  std::cout << std::cin.rdstate() << '\n';
  std::cout << std::cin.good() << '\n';
  std::cout << std::cin.fail() << '\n';
  std::cout << std::cin.bad() << '\n';
  std::cout << std::cin.eof() << '\n';

  std::cin.clear();
  std::cout << std::cin.rdstate() << '\n';
  std::cout.flush();
  return 0;
}