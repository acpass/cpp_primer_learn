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
      if(i>(v.size()-1)||i>(sizeof(arr)-1))
        throw out_of_range("big index");
      cout << v[i] << arr[i] << endl;
    } catch (out_of_range err) {
      cout << err.what() << '\n' << "you are out of range!" << endl;
      break;
    }
  }
  cout << "terminal" << endl;
  return 0;
}