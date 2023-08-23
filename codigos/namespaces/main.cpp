#include <iostream>
#include "mymath.h"

using namespace math;
using namespace std;

int main() {
  const int a{5}, b{10};

  cout << sum(a, b) << endl;    
  cout << sub(a, b) << endl;
  cout << mul(a, b) << endl;
  cout << math::div(b,a) << endl;

  return 0;
}