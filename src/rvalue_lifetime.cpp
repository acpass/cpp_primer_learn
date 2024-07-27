#include <cstddef>
#include <iostream>
// include the library of epoll
#include <sys/epoll.h>
class A {
public:
  A() { std::cout << "A()" << std::endl; }
  A(const A &) { std::cout << "A(const A &)" << std::endl; }
  A(A &&) { std::cout << "A(A &&)" << std::endl; }
  ~A() { std::cout << "~A()" << std::endl; }
  A &operator=(const A &) {
    std::cout << "A &operator=(const A &)" << std::endl;
    return *this;
  }
  A &operator=(A &&) {
    std::cout << "A &operator=(A &&)" << std::endl;
    return *this;
  }
};

void test(A &&) { std::cout << "test(A &&)" << std::endl; }
void test_lvalue(const A &) { std::cout << "test_lvalue(A &)" << std::endl; }
void test_copy(A) { std::cout << "test_copy(A)" << std::endl; }

// a quick sort function
void quick_sort(int *arr, int left, int right) {
  if (left >= right)
    return;
  int i = left, j = right;
  int key = arr[left];
  while (i < j) {
    while (i < j && arr[j] >= key)
      j--;
    arr[i] = arr[j];
    while (i < j && arr[i] <= key)
      i++;
    arr[j] = arr[i];
  }
  arr[i] = key;
  quick_sort(arr, left, i - 1);
  quick_sort(arr, i + 1, right);
}
// explain upside function
// 1. if left >= right, return
// 2. set i = left, j = right, key = arr[left]
// 3. while i < j, find the first element that is less than key from right to
// left, and set it to arr[i]
// 4. while i < j, find the first element that is greater than key from left to
// right, and set it to arr[j]
// 5. set arr[i] = key to make sure that all elements in the left of i are less
// than key, and all elements in the right of i are greater than key
// 6. quick_sort(arr, left, i - 1) to sort the left part
// 7. quick_sort(arr, i + 1, right) to sort the right part

// demo to use quick_sort
void demo_quick_sort() {
  int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
  quick_sort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
  for (std::size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    std::cout << arr[i] << " ";
  std::cout << std::endl;
}

int main() {
  test(A());

  demo_quick_sort();
  test_lvalue(A());
  test_lvalue(std::move(A()));

  return 0;
}