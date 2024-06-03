#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct DATA_PAIR {
  string key;
  vector<string> data;
};

int main() {
  ifstream data_file("/root/code/CPP_learn/test_file/test_data");
  if (!data_file.is_open())
    exit(1);

  vector<DATA_PAIR> map;
  string line;

  while (getline(data_file, line)) {
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

  for (const auto &i : map) {
    cout << "key: " << i.key << " datas:";
    for (const auto &data : i.data) {
      cout << " " << data;
    }
    cout << '\n';
  }
  cout << endl;

  for (const auto &i : map) {
    int valid = 1;
    ostringstream out_record;
    out_record << i.key << ' ';
    if (i.data.empty())
      valid = 0;
    for (const auto &num : i.data) {
      if (num[0] != '1')
        out_record << num << ' ';
      else {
        valid = 0;
        break;
      }
    }
    if (valid)
      cout << out_record.str() << '\n';
  }
  cout << endl;

  return 0;
}