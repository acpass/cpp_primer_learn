#ifndef _STATIC_MEMBER_HPP_
#define _STATIC_MEMBER_HPP_

#include <iostream>
#include <string>

class test_class
{
private:
  static int var1;
  int test_a;
  int test_b;
  static int initvar1();
  int _initvar1();

public:
  void _var(int i)
  {
    var1 = i;
  }
  static void var(int i)
  {
    var1 = i;
  }

  int _var()
  {
    return var1;
  };
  static int var()
  {
    return var1;
  }

  void call_count()
  {
    static int cnt;
    std::cout << ++cnt << std::endl;
  }
};

#endif