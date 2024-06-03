#pragma once
#include <iostream>
#include <typeinfo>

class Base {

protected:
  int a;

  virtual bool equal(const Base &rhs) {
    return dynamic_cast<const Base &>(rhs).a == this->a;
  }

public:
  Base(int v = 0) : a(v) {}
  Base(const Base &) = default;
  Base &operator=(const Base &obj) {
    a = obj.a;
    return *this;
  }
  virtual ~Base() {}

  bool operator==(const Base &rhs) {
    std::cout << '\n';
    std::cout << typeid(*this).name() << "==" << typeid(rhs).name() << "?";
    if (typeid(*this) != typeid(rhs))
      return false;
    else
      return equal(rhs);
  }
};

class Derived : public Base {

protected:
  int b;

  virtual bool equal(const Base &rhs) override {
    return dynamic_cast<const Derived &>(rhs).a == this->a &&
           dynamic_cast<const Derived &>(rhs).b == this->b;
  }

public:
  Derived(int v1 = 0, int v2 = 0) : Base(v1), b(v2) {}
  Derived(const Derived &) = default;
  Derived &operator=(const Derived &obj) {
    Base::operator=(obj);
    this->b = obj.b;
    return *this;
  }

  virtual ~Derived() override {}
};