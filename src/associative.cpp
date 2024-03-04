#include <bits/stdc++.h>
using namespace std;

bool compare_global_test(int a, int b)
{
  return a > b;
}

int main()
{
  ostream_iterator<string> cout_iter(cout, " ");
  ifstream fd_in("../test_file/file1");
  if (fd_in.is_open())
  {
    map<string, string::size_type> word_count;
    set<string> exclude_set{"an", "the"};
    cout << exclude_set.insert("a").second << ' ';
    cout << exclude_set.insert("the").second << ' ';
    cout << endl;
    copy(exclude_set.cbegin(), exclude_set.cend(), cout_iter);
    cout << '\n';
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

    word_count.emplace("able", 5);           //the insert is ignored
    word_count.insert_or_assign("woke", 10); //the insert(assign) is done

    for (const auto &i : word_count)
    {
      cout << i.first << " occurs " << i.second << ((i.second > 1) ? " times" : " time") << ".\n";
    }
  }
  else
  {
    cout << "failed to open the file";
  }
  fd_in.close();
  cout << endl;

  auto compare = [](int a, int b) -> bool {
    return a > b;
  };

  map<int, string, decltype(compare_global_test) *>
      compare_spe_test_map(compare_global_test);

  compare_spe_test_map = {{1, "1"}, {7, "7"}, {3, "3"}};

  for (const auto &i : compare_spe_test_map)
  {
    cout << i.first << ":" << i.second << " ";
  }
  cout << endl;

  map<int, string>::mapped_type a; //the value's type: string
  map<int, string>::value_type b;  //the elements' type in the map: pair<key, value>

  fd_in.open("../test_file/file1");
  if (fd_in.is_open())
  {
    multimap<string::size_type, string> word_size;
    string word;
    while (fd_in >> word)
    {
      string out_word;
      auto insert_iter = back_inserter(out_word);
      copy_if(word.begin(), word.end(), insert_iter, ::isalpha);
      transform(out_word.begin(), out_word.end(), out_word.begin(), ::tolower);
      if (!out_word.empty())
        word_size.emplace(out_word.size(), out_word);
    }
    
  }
  else
  {
    cout << "failed to open the file";
  }
  cout << endl;

  return 0;
}