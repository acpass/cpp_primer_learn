#include <vector>
#include <iostream>
#include <deque>
#include <array>
using namespace std;

int main()
{
  vector<int> v(100, 0), v2(50, 2);
  const vector<int> cv(100, 0);
  vector<double> dv(100, 0.0);
  deque<int> deq;

  vector<int>::iterator it = v.begin();
  vector<int>::const_iterator cit = it + 3;
  vector<int>::size_type sz;
  vector<int>::value_type int_v;
  vector<int>::difference_type diff = cit - it;
  vector<int>::reference int_ref = v[0]; // elem's ref
  vector<int>::const_reference int_cref = v[3];

  *it = 1;
  // *cit = 1;  not a lvalue

  auto citer = cv.begin(); // call the const version of begin

  v.swap(v2);

  cout << v.size() << ' ' << v.max_size() << endl;
  cout << v2.size() << ' ' << v2.max_size() << endl;
  cout << dv.size() << ' ' << dv.max_size() << endl;

  // because the constructor that take a single number as its parameter is explicite
  // we can use explicit type cast to cast a number of type vector<int>::size_type to a vector<int>
  vector<int> castv(static_cast<vector<int>>(static_cast<vector<int>::size_type>(10)));
  for (auto i : castv)
  {
    cout << i << ' ';
  }
  cout << endl;

  array<int, 100> arr{1, 1, 1};                      // value-init
  array<int, 100> arr_default;                       // default-init
  cout << arr[50] << ' ' << arr_default[50] << endl; // both of which are initialized to 0;
  arr = arr_default;                                 // not as same as built-in array, copy
  arr[2] = 10;
  arr = {0, 1}; // assignment, it should not be allowed but no warning or error
  // in fact, brace elision take care of it and finish the rest of the right brace object
  cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl; // upper assignment change the whole arr, so arr[2] is value-init

  vector<int> vec1{1, 2, 3}, vec2{4, 5, 6, 7, 8};
  auto vecb = vec1.begin(), vece = vec1.end();
  swap(vec1, vec2); // do not change the former iter
  for (; vecb != vece; vecb++)
  {
    cout << *vecb << ' ';
  }
  cout << endl;

  vector<string> sv;
  sv.push_back("123");
  sv.emplace_back("1234");
  sv.emplace_back(12, 'a');

  auto sit = sv.begin();
  sit = sv.insert(sit, "1234");
  sit = sv.emplace(sit, 12, 'c');
  for (auto i : sv)
  {
    cout << i << ' ';
  }

  cout << endl;

  return 0;
}