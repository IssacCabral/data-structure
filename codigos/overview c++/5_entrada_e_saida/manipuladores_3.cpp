#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  int number{12345};

  cout << setfill ('*');

  cout << "\"" << left
       << setw(10)
       << number << "\"" << endl;

  cout << "\"" << number << "\"" << endl;

  cout << "\"" << right
       << setw(10)
       << number << "\"" << endl;
       
  return 0;
}