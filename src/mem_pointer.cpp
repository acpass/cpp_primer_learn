#include <functional>
#include <iostream>
#include <string>

template <typename T> T add_two(T a, T b) { return a + b; }

class point_test {
  int a;
  int b;

public:
  point_test(int a, int b) : a(a), b(b) {}
  int add() const { return a + b; }
};

int main() {
  std::cout << "Hello, Capilot!" << std::endl;
  int a = 1, b = 2;
  std::string c = "Hello, ", d = "Capilot!";
  std::cout << add_two(c, d) << std::endl; // Hello, Capilot!

  int (point_test::*addfun)() const;
  addfun = &point_test::add;
  std::cout << (point_test(1, 2).*addfun)() << std::endl;

  auto addfun2 = std::bind(&point_test::add, std::placeholders::_1);
  std::cout << addfun2(point_test(1, 2)) << std::endl;

  auto addfun3 = std::mem_fn(&point_test::add);
  std::cout << addfun3(point_test(1, 2)) << std::endl;

  std::function<int(const point_test &)> addfun4 = &point_test::add;
  std::cout << addfun4(point_test(1, 2)) << std::endl;

  return 0;
}