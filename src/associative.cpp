#include <bits/stdc++.h>
using namespace std;

bool compare_global_test(int a, int b)
{
  return a > b;
}

int main()
{
  ifstream fd_in("../test_file/file1");
  if (fd_in.is_open())
  {
    map<string, string::size_type> word_count;
    set<string> exclude_set{"a", "an", "the"};
    string word;
    while (fd_in >> word)
    {
      string out_word;
      auto insert_iter = back_inserter(out_word);
      copy_if(word.begin(), word.end(), insert_iter, ::isalpha);
      transform(out_word.begin(), out_word.end(), out_word.begin(), ::tolower);
      if (!out_word.empty() &&
          (find(exclude_set.cbegin(), exclude_set.cend(), out_word) == exclude_set.end()))
        ++word_count[out_word];
    }

    for (const auto &i : word_count)
    {
      cout << i.first << " occurs " << i.second << ((i.second > 1) ? " times" : " time") << ".\n";
    }
  }
  else
  {
    cout << "failed to open the file";
  }
  cout << endl;

  auto compare = [](int a, int b) -> bool {
    return a > b;
  };

  map<int, string, decltype(compare_global_test) *>
      compare_spe_test_map(::compare_global_test);
  compare_spe_test_map = {{1, "1"}, {7, "7"}, {3, "3"}};

  for (const auto &i : compare_spe_test_map)
  {
    cout << i.first << ":" << i.second << " ";
  }
  cout << endl;

  return 0;
}