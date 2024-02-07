#include <iostream>
#include <string>
#include <screen_window.hpp>

int main()
{
  Screen s(std::cin);
  s.set_size(5, 5);
  print(std::cout, s);

  std::cout << std::endl;
  const Screen s1("abcdefghijk", 5, 5);

  print(std::cout, s1);

  for (int i; std::cin >> i;)
  {
    if (s1.set_cursor(i))
    {
      std::cout << s1.get_cursor_content() << std::endl;
    }
    else
    {
      std::cout << "out of range" << std::endl;
    }
  }
  return 0;
}