#include <iostream>
#include <string>
#include "screen_window.hpp"

std::istream &read(std::istream &is, Screen &scr)
{
  return is >> scr.contents;
}

std::ostream &print(std::ostream &os, const Screen &scr)
{
  Screen::pos out_hi = 1, out_wi = 1;

  os << "  ";
  for (int i = 0; i < scr.width; ++i)
  {
    os << i + 1;
  }
  os << "\n\n";

  for (auto i : scr.contents)
  {
    if (out_hi <= scr.height)
    {
      if (out_wi <= scr.width)
      {
        if (out_wi == 1)
          os << out_hi << " ";
        os << i;
        ++out_wi;
      }
      else
      {
        os << '\n';
        out_wi = 1;
        ++out_hi;
      }
    }
    else
    {
      break;
    }
  }

  for (; out_wi <= scr.width; ++out_wi)
    os << ' ';
  os << '\n';
  ++out_hi;

  for (; out_hi <= scr.height; ++out_hi)
    os << out_hi << " \n";

  std::cout.flush();
  return os;
}

class scope_test
{
private:
  int test;

public:
  int test_fn(char);
};

double test;

int scope_test::test_fn(char test1)
{
  test; // because the funtion body is in the scope of class scope_test, the test refer to the member var test
}