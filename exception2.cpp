#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
using namespace std;


int main() {
  vector v = {1, 2, 3};
  int arr[3] = {1, 2, 3};
  for (int i = 0; i <= 5; i++) {
    try{
      cout << v[i] << arr[i] << endl;
    } catch (out_of_range err) {
      cout << err.what() << '\n' << "you are out of range!" << endl;
    }
  }
  cout << "terminal" << endl;
  return 0;
}