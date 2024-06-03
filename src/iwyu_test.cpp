#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
int main() {
  std::vector<std::string> sv{"123", "23", "3231"};
  std::vector<std::string> sv2;
  auto it = std::inserter(sv2, sv2.begin());

  std::copy_if(
      sv.cbegin(), sv.cend(), it,
      [](const decltype(sv)::value_type &v) { return v.size() == 3 ? 1 : 0; });

  for (const auto &v : sv2)
    std::cout << v;

  return 1;
}
