
#include <array>
#include <cstddef>
#include <cstdio>
#include <print>
#include <string>
#include <string_view>

const std::string target = "ABACCBACDBACABACBABADBACBACB";
constexpr std::string pattern = "ABACBABAD";

template <std::size_t N>
void build_next(std::string_view p, std::array<unsigned, N> &next) {

  static_assert(N != 0);

  std::println("N={}, p.size={}", N, p.size());

  auto pre = 0;
  next[0] = 0;

  for (unsigned i = 1; i < N; i++) {
    if (p[pre] == p[i]) {
      next[i] = next[i - 1] + 1;
      pre++;
    } else {
      unsigned sub_pre = next[i - 1];
      unsigned back = next[sub_pre];
      pre = back;
    }
  }
}

int main() {
  std::array<unsigned, pattern.size() - 1> next;

  std::println("sizeof(next): {}", pattern.size());

  build_next(pattern, next);

  for (auto i : next)
    std::print("{} ", i);
  std::println("");

  auto pattern_ptr = pattern.cbegin(), target_ptr = target.cbegin();

  for (; pattern_ptr != pattern.cend() && target_ptr != target.cend();
       target_ptr++) {

    if (*target_ptr == *pattern_ptr)
      pattern_ptr++;
    else {
      pattern_ptr = pattern.cbegin() + next[pattern_ptr - pattern.cbegin()];
    }
  }

  if (pattern_ptr == pattern.cend()) {
    std::println("Pattern found at position: {}",
                 target_ptr - pattern.size() - target.cbegin());
  } else {
    std::println("no pattern found");
  }
}
