#include <bits/stdc++.h>
using namespace std;

struct test {
  static int count;
  int id;
  test() { id = count++; }
  ~test() { cout << id << endl; }
};

int test::count = 0;

int main() {
  auto p1 = make_shared<int>(53);
  auto p2(p1);
  auto p3 = p2;
  auto p4 = make_shared<int>(*p3);
  auto &p4_obj_ref = *p4;

  cout << p1.use_count() << endl;
  cout << p4.use_count() << endl;
  cout << &p4_obj_ref << endl;
  p4 = p1;
  cout << p4.use_count() << endl;
  cout << &p4_obj_ref << endl;

  auto &p4_ref = p4;
  cout << p4.use_count() << endl;
  // try
  // {
  //   while (1)
  //   {
  //     auto p = new string(100000000000, 'a');
  //     cout << 1;
  //   }
  // }
  // catch (bad_alloc err)
  // {
  //   cout << err.what() << endl;
  //   exit(1);
  // }

  shared_ptr<vector<int>> p5(new vector<int>{1, 2, 3});
  vector<int> v{1, 2, 3};
  auto builtin_p1 = new vector<int>{1, 2, 3};
  cout << builtin_p1->back() << ' ';
  cout << p5->back() << endl;
  {
    shared_ptr<vector<int>> p6(builtin_p1, [](decltype(builtin_p1)) {
      cout << "it should not be deleted" << endl;
    });
    // shared_ptr<vector<int>> p7(p5.get());
  }
  cout << builtin_p1->back() << ' ';
  cout << p5->back() << endl;

  unique_ptr<int> uq1(new int(42));
  unique_ptr<int> uq2(uq1.release());

  // try {
  //   int small = 1;
  //   auto p = new string[small]{"", "", "", "", ""};
  //   cout << p[1] << endl;
  // } catch (bad_array_new_length err) {
  //   cout << err.what() << endl;
  // }

  auto foo = [](int *) { cout << "one delete" << endl; };

  unique_ptr<test[]> utp(new test[5]);
  cout << utp[0].id << endl;
  utp.release();

  allocator<string> alloc;
  auto const alp1 = alloc.allocate(5);
  for (auto p = alp1; p != alp1 + 5; p++) {
    alloc.construct(p, 5, 'a');
  }
  alloc.destroy(alp1 + 5);
  cout << alp1[4] << endl;
  for (auto p = alp1; p != alp1 + 5; p++) {
    alloc.destroy(p);
  }
  alloc.deallocate(alp1, 5);

  return 0;
}