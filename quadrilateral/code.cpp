#include <iostream>
using namespace std;

int main(int args, char** argv) {

  // receive n and preprocessing
  int n = 0;
  cout << "Input: ";
  cin >> n;
  if (n < 0) {
    cout << "Wrong input!" << endl;
    return -1;
  }
  if (n % 2 == 0)
    ++n;
  // print quadrilateral
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < abs(n/2 - i); ++j)
      cout << "  ";
    for (int k = 0; k < (2 * (n/2 - abs(n/2 - i)) + 1); ++k)
      cout << "* ";
    cout << endl;
  }

  return 0;
}