#include <iostream>

using namespace std;

int main() {
  int count = 10;

  int *p;
  p = &count;

  cout << "Conteúdo de p: " << p << endl;
  cout << "Conteúdo apontado por p: " << *p << endl;

  *p = 12;

  cout << "Conteúdo apontado por p: " << *p << endl;
  cout << "Conteúdo de count: " << count << endl;
  
  return 0;
}