#include <iostream>

using namespace std;

int main() {
  string str;

  cout << ">>>: ";

  while(getline(cin, str)) {
    cout << "digitado: " << str << "\n";
    cout << "CTRL+D ou CTRL+Z para encerrar\n";
    cout << ">>>: ";
  }

  return 0;
}