#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  double root2{sqrt(2.0)};
  cout << "sqrt(2) = " << root2 << endl;
  cout << scientific << "sqrt(2) = " << root2 << endl;

  cout << "Square root of 2 with precisions 0-9. \n";
  cout << fixed;

  for(int places{0}; places <= 9; ++places) {
    cout << setprecision(places) << root2 << "\n";
  }

  return 0;
}