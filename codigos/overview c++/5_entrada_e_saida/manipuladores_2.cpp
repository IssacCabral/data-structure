#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  double number1{4.0 / 2.0};
  double number2{4.0 / 3.0};

  cout << showpos;

  cout << number1 << "\n"
       << number2 << "\n\n" << flush;

  cout << fixed << setprecision(2);

  cout << number1 << "\n"
       << number2 << endl;
       
  return 0;
}