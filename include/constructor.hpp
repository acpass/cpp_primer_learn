#pragma once
#include <initializer_list>
#include <iostream>
#include <string>

class Constructor {
  int a;

public:
  Constructor(int x) : a(x) {}
  Constructor(const Constructor &c) : a(c.a) {
    std::cout << "Copy constructor called" << std::endl;
  }
  Constructor &operator=(const Constructor &c);
};

class strptr_in {
  std::string *ptr = nullptr;
  int count = 0;

public:
  strptr_in(std::string str = std::string())
      : ptr(new std::string(str)), count(str.length()) {}

  strptr_in(const strptr_in &obj)
      : ptr(new std::string(*obj.ptr)), count(obj.count) {}

  strptr_in &operator=(const strptr_in &obj) {
    auto newptr = new std::string(*obj.ptr);
    count = obj.count;
    delete ptr;
    ptr = newptr; // for self assignment
    return *this;
  }

  ~strptr_in() { delete ptr; }
};

class deleted_copy {
  int a;

public:
  deleted_copy(int x) : a(x) {}
  deleted_copy(const deleted_copy &) = delete;
  deleted_copy &operator=(const deleted_copy &) = delete;
  ~deleted_copy() = default;
};

class own_shared_ptr {
  std::string *ptr;
  int *ref_cnt;

public:
  own_shared_ptr(std::string str = std::string())
      : ptr(new std::string(str)), ref_cnt(new int(1)) {}

  own_shared_ptr(const own_shared_ptr &obj) {
    ptr = obj.ptr;
    ref_cnt = obj.ref_cnt;
    *obj.ref_cnt += 1;
  }

  ~own_shared_ptr() {
    *ref_cnt -= 1;
    if (*ref_cnt == 0) {
      delete ptr;
      delete ref_cnt;
    }
  }

  own_shared_ptr &operator=(const own_shared_ptr &obj) {

    *ref_cnt -= 1;
    auto old_cnt = ref_cnt;
    auto old_ptr = ptr;
    ptr = obj.ptr;
    ref_cnt = obj.ref_cnt;
    *this->ref_cnt += 1;
    if (*old_cnt == 0) {
      delete old_ptr;
      delete old_cnt;
    }
    return *this;
  }
};

class Y_without_move {
  int a;

public:
  Y_without_move() : a(1) {}
  Y_without_move(const Y_without_move &y) : a(y.a) {}
  // Y_without_move(Y_without_move &&y) : a(y.a) {}

  friend class hasY;
};

class hasY {
  Y_without_move y;

public:
  hasY() = default;
  hasY(const hasY &y) = default;
  // hasY(hasY &&y) = delete;
};

class hasYptr {
  hasY *ptr;

public:
  hasYptr(hasY *p) : ptr(p) {}

  hasY &operator*() { return *this->ptr; }

  // for Yptr->print(), the compiler unroll it to (*return_ptr).print()
  hasY *operator->() { return this->ptr; }
};

class myclass {
  int a;

public:
  explicit myclass(int v) : a(v) {};

  // operator int() const
  // {
  //   return a;
  // }

  myclass &operator+=(int rhs) {
    this->a += rhs;
    return *this;
  }

  myclass operator+(int rhs) const {
    myclass ret = *this;
    return ret += rhs;
  }

  friend myclass operator+(const myclass &lhs, int rhs) {
    myclass ret = lhs;
    return ret += rhs;
  }

  friend myclass operator+(int lhs, const myclass &rhs) {
    myclass ret = rhs;
    return ret += lhs;
  }

  friend std::ostream &operator<<(std::ostream &os, const myclass &obj) {
    os << obj.a;
    return os;
  }
};

class Init_Assign {
  int a;

public:
  Init_Assign(int v = 0) : a(v) {
    std::cout << "Init_Assign(int v = 0)" << std::endl;
  }
  Init_Assign(const Init_Assign &obj) : a(obj.a) {
    std::cout << "Init_Assign(const Init_Assign &obj)" << std::endl;
  }
  Init_Assign(std::initializer_list<int> il) : a(*il.begin()) {
    std::cout << "Init_Assign(std::initializer_list<int> il)" << std::endl;
  }
  Init_Assign &operator=(const Init_Assign &obj) {
    a = obj.a;
    std::cout << "Init_Assign operator(obj)" << std::endl;
    return *this;
  }
  Init_Assign &operator=(int v) {
    a = v;
    std::cout << "Init_Assign operator(int v)" << std::endl;
    return *this;
  }
};