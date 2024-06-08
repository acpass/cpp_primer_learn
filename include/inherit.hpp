#pragma once

#include <iostream>
#include <map>
#include <string>

class base_book {
  std::string _isbn;

protected:
  long double price;

public:
  base_book(std::string isbnvalue = "", long double p = 0.0)
      : _isbn(std::move(isbnvalue)), price(p) {}

  virtual ~base_book() = default;

  std::string isbn() const { return _isbn; }

  virtual long double cnt_price(size_t num) const { return num * price; }
};

class bulk_sale_book : public base_book {
  std::map<std::size_t, double> discount_map;

public:
  long double cnt_price(size_t num) const override {
    if (discount_map.empty()) {
      return num * price;
    } else {
      return 0; // not implemented
    }
  }
};

class name_hidden_base {
protected:
  int mem;

public:
  name_hidden_base() : mem(0) {}
  virtual int get_mem() const {
    std::cout << "get from base" << std::endl;
    return mem;
  }

  void foo_hidden_test() { std::cout << "base called" << std::endl; }

  void base_foo() { std::cout << "a func from base called" << std::endl; }
};

class name_hidden_derived : public name_hidden_base {
private:
  int mem;

public:
  name_hidden_derived(int i) : mem(i) {}
  virtual int get_mem() const {
    std::cout << "get from derived" << std::endl;
    return name_hidden_base::mem;
  }

  void foo_hidden_test(int i) { std::cout << "derived called" << std::endl; }
};

void hidden_test(const name_hidden_base &obj);