#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void ignore_line() {
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int readInt() {
  while(true) {
    int value;

    cin >> value;

    if (cin.fail()) {
      cerr << "fail: enter a valida integer\n";
      cin.clear();
      ignore_line();
    } else {
      ignore_line();

      return value;
    }
  }
}

int main() {
  int x = readInt();

  cout << "x = " << x << endl;
  
  return 0;
}