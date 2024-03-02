#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

void lambda_test(int a, bool (*foo)(int))
{
  foo(a);
}

void show(int first, int second)
{
  cout << first << ' ' << second << endl;
}

int main()
{
  vector<int> v{1, 2, 3, 4, 5, 1, 5, 3, 6, 8, 4, 3};
  sort(v.begin(), v.end(),
       [](int a, int b) -> bool {
         return a < b;
       });
  auto iter = find_if(v.cbegin(), v.cend(),
                      [](int a) {
                        return a > 5;
                      });
  for (; iter != v.cend(); iter++)
  {
    cout << *iter << ' ';
  }
  cout << endl;

  auto foo([](int a) -> bool {
    cout << a << endl;
    return 1;
  });
  //foo is a object of type lambda (int)->bool

  lambda_test(5, foo);

  auto foo2 = [] {
    cout << __FILE__ << ' ' << __LINE__ << endl;
  };

  foo2();

  vector v2{1, 2, 3};

  cout <<
      [v2]() -> string {
    return string("number") + ((v2.size() > 1) ? "s" : "");
  }()
                    << " count is " << v2.size() << endl;

  for_each(v.cbegin(), v.cend(),
           [](const int a) {
             if (a > 3)
               cout << a << ' ';
           });
  cout << endl;

  int i = 0;

  auto foo3([i]() mutable {
    cout << i << ' ';
    i++;
  });

  foo3();
  foo3();
  foo3();
  cout << endl;

  auto newCallable = bind([](int first, int second) {
    cout << first << ' ' << second << endl;
  },
                          _1, 8);

  auto newCallable2 = bind(show, _1, 9);

  newCallable(2);
  newCallable2(3);

  auto outputfoo([](ostream &os, const string &s) {
    os << s;
  });

  auto output_callable = bind(outputfoo, ref(cout), _1);

  output_callable(string("123"));
  cout << endl;
  i = 1;

  cout << i << ' ';
  [](int a) {
    a = 5;
  }(ref(i));
  cout << i << endl;

  return 0;
}