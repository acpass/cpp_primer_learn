#pragma once
#include <iostream>

void real_foo(int, int &, int &&);

template <typename T> T template_add(const T &arg1, const T &arg2) {
  static int a = 0;
  std::cout << "call count: " << ++a << std::endl;
  return arg1 + arg2;
}

template <typename T, unsigned N> unsigned int array_size(const T (&)[N]) {
  return N;
}

template <typename T1, typename T2, typename T3>
void proxy_foo(T1 &&a, T2 &&b,
               T3 &&c) // a is passed by value and the constness is also losen,
                       // b can not accept a rvalue, but c can be paassed with
                       // any kinds of value while preserve their properties
{
  // but c is converted to a lvalue as it was passing in as (binding to) a
  // variable c... so std::move is needed
  real_foo(a, b, std::move(c));

  // instead, to solve this problem, we should use std::forward in <utility>
  // the return type of forward<T> is T&&, so when we pass a lvalue ref T&, it
  // will be T& &&, which will collapse to T& so arguements preserve their
  // lvalue or rvalue property
  real_foo(std::forward<T1>(a), std::forward<T2>(b), std::forward<T3>(c));
}

template <typename T> void print(std::ostream &os, const T &arg) { os << arg; }

template <typename T, typename... Args>
void print(std::ostream &os, const T &arg1,
           const Args &...args) // expansion pattern: const Args&
{
  os << "<pack count: " << sizeof...(Args) << ">";
  os << arg1 << ", ";
  print(os, args...);
}