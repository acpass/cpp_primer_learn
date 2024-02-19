#include <vector>
#include <iostream>
#include <deque>
#include <array>
#include <stdexcept>
#include <forward_list>
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
  cout << arr[50] << ' ' << arr_default[50] << endl; // both of which are initialized to 0;  in another environment, the later one is not initialized
  arr = arr_default;                                 // not as same as built-in array, copy
  arr[2] = 10;
  arr = {0, 1}; // assignment, it should not be allowed but no warning or error
  // in fact, brace elision take care of it and finish the rest of the right brace object
  cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl; // upper assignment change the whole arr, so arr[2] is value-init

  vector<int> vec1{1, 2, 3}, vec2{4, 5, 6, 7, 8};
  auto vecb = vec1.begin(), vece = vec1.end();
  swap(vec1, vec2); // do not change the former iter

  vec2.front() = 5; // return a ref, so we can change it

  for (; vecb != vece; vecb++)
  {
    cout << *vecb << ' ';
  }
  cout << endl;

  try
  {
    cout << vec1.at(50) << endl;
  }
  catch (out_of_range err)
  {
    cout << err.what() << endl;
  }

  forward_list<int> fl{1, 2, 3, 4, 5};

  auto fl_beg = fl.begin(), fl_end = fl.end();

  fl.push_front(8);

  fl.insert_after(fl_beg, 12); // insert after iter

  for (; fl_beg != fl_end; fl_beg++)
    cout << *fl_beg << ' ';

  cout << endl;

  for (auto i : fl)
    cout << i << ' ';

  cout << endl;

  vector<int> vec_insert{1, 2, 3};

  auto insert_iter = vec_insert.begin() + 1;
  cout << *insert_iter << endl;
  vec_insert.insert(insert_iter, 12); // insert before iter

  auto a1 = fl.front();
  decltype(fl.front()) a2 = fl.front(); // decltype return a type of the ref, but auto return the origin type which is int;

  vec_insert.erase(vec_insert.begin(), vec_insert.begin());

  vec_insert.erase(vec_insert.end(), vec_insert.end());

  for (auto i : vec_insert)
  {
    cout << i << ' ';
  }
  cout << endl;

  cout << vec_insert.size() << '/' << vec_insert.capacity() << ' ';
  vec_insert.shrink_to_fit();
  cout << vec_insert.size() << '/' << vec_insert.capacity() << ' ';
  vec_insert.reserve(vec_insert.size() * 2);
  cout << vec_insert.size() << '/' << vec_insert.capacity() << ' ';
  cout << endl;

  string s1("123");
  for (int i = 5;;)
  {
    try
    {
      string s2(s1, i);
      cout << i << endl;
      break;
    }
    catch (out_of_range err)
    {
      cout << err.what() << endl;
      i--;
      continue;
    }
  }

  return 0;
}