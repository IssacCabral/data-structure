#include <iostream>

int main() {
  int array [5] = { 0 ,1 ,2 ,3 ,4 };
  int *ptr = array;

  std::cout << ptr << ": " << *ptr << "\n";
  std::cout << ptr+1 << ": " << *(ptr+1) << "\n";
  std::cout << ptr+2 << ": " << *(ptr+2) << "\n";
  std::cout << ptr+3-2 << ": " << *(ptr+3-2) << "\n";

  // Percorrendo um array
  int *p = array, *b = array+4;

  while(p <= b) {
    std::cout << *p << " ";
    p++;
  }

  std::cout << std::endl;

  return 0;
}