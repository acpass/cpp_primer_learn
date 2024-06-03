#include <exception>
#include <iostream>
#include <stdexcept>

class test_class {
  static int id;
  int own_id;

public:
  test_class() {
    own_id = id++;
    std::cout << "construct id: " << own_id << '\n';
  }

  ~test_class() {
    std::cout << "destroy id: " << own_id << '\n';
    // throw std::runtime_error("destructor");
  }
};

int test_class::id = 0;

void thrower() {
  test_class obj1;
  // throw std::runtime_error("throw in func");
  try {
    try {
      test_class obj2;
      throw std::runtime_error("throw in try");
      std::cout << "after throw" << '\n';

      int a = 1;
    } catch (std::runtime_error err) {
      std::cerr << "catch in func inner try: ";
      std::cerr << err.what() << '\n';
    }
    std::cout << "after inner try catch" << '\n';
  } catch (std::runtime_error err) {
    std::cerr << "catch in func outter try: ";
    std::cerr << err.what() << '\n';
  }
  std::cout << "exit func" << '\n';
}

int main() {
  thrower();
  try {
    thrower();
  } catch (std::runtime_error err) {
    std::cerr << "catch in main: ";
    std::cerr << err.what() << '\n';
  }
}