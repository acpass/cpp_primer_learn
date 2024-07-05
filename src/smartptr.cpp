
#include <boost/type_index.hpp>
#include <memory>
#include <print>
#include <utility>

class Base {
public:
  Base() { std::println("Construct B"); };
  Base(Base &B) { std::println("Copy B"); }
  Base(Base &&B) { std::println("Move B"); }
  virtual ~Base() = default;

  virtual void print() const { std::println("Print B"); }
};

class Derived : public Base {
public:
  Derived() = default;
  virtual ~Derived() = default;

  void print() const override { std::println("Print D"); }
};

std::unique_ptr<Base> get_D() { return std::make_unique<Derived>(); }
// here we use a return by value strategy to return a unique_ptr
// it works, by in concept, a rvalue is needed
// that's because when we return by value from a function
// if the assignment(construction) statement is accepted by a variable whose
// type and cv-qualifier is the same as the return type
// the rvo will be applied, and the return value will be moved to the variable
// 12.8 §34 and §35
auto lambda = [](auto v) { std::println("{}", v); };

auto deleter = [](Base *b) {
  std::println("Delete");
  delete b;
};

Base get_B() {
  Base b;
  // return std::move(b);
  // wrong!! it omit the rvo

  // proper method
  return b;
  // a local viarable should be returned by value, the rvo will be applied
}

int main() {
  auto b = get_D();
  auto d = std::make_unique<Derived>();

  std::println(
      "{}",
      boost::typeindex::type_id_with_cvr<decltype(lambda)>().pretty_name());

  b->print();

  {
    std::unique_ptr<Base, decltype(deleter)> b2(new Derived(), deleter);

    std::shared_ptr<Base> b3 = std::move(b2);
  }

  std::weak_ptr<Base> wp;

  {
    auto sp = std::make_shared<Derived>();
    wp = sp;
  }

  if (auto sp = wp.lock()) {
    sp->print();
  } else {
    std::println("Expired");
  }

  try {
    std::shared_ptr<Base> sp(wp);
  } catch (std::bad_weak_ptr &e) {
    std::println("Exception: {}", e.what());
  }

  auto b2 = get_B();
  // b inside get_B is actually constructed in the location of b2

  return 0;
}