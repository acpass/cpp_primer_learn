#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct DATA_PAIR
{
  string key;
  vector<string> data;
};

int main()
{
  ifstream data_file("/root/code/CPP_learn/test_file/test_data");
  if (!data_file.is_open())
    exit(1);

  vector<DATA_PAIR> map;
  string line;

  while (getline(data_file, line))
  {
    string tmp;
    DATA_PAIR pair;

    istringstream record(line);
    if (record >> tmp)
      pair.key = tmp;
    while (record >> tmp)
      pair.data.push_back(tmp);
    if (!pair.key.empty()) // skip empty line
      map.push_back(pair);
  }

  for (auto i : map)
  {
    cout << "key: " << i.key << " datas:";
    for (auto data : i.data)
    {
      cout << " " << data;
    }
    cout << '\n';
  }
  cout.flush();

  return 0;
}