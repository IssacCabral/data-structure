#include <iostream>

using namespace std;

int main() {
  float f = 45.78;
  int *ptr = &f; // erro
  
  int i = 54;
  float *f2 = &i; // erro

  float *fptr = &f; // ok
  int *iptr = &i; // ok

  fptr = iptr; // erro 
  float *f3 = fptr; // ok

  std :: cout << *fptr << ", " << *iptr << std :: endl ;

  return 0;
}