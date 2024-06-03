#pragma once

#include <iostream>

class base
{
  int a;

public:
  base() : a(0) {}
  base(const base &obj) =default;

  virtual ~base() = default;

};