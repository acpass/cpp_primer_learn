#include <boost/type_index.hpp>
#include <print>
int main() {
  int a[]{1, 2, 3, 4, 5, 6, 7};
  std::println("{}",
               boost::typeindex::type_id_with_cvr<decltype(a)>().pretty_name());
  return 0;
}