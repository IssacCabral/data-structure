#include <iostream>

using namespace std;

int main() {
  /**
   * c++ suporta dois tipos diferentes de string:
   * strings como array de caracteres terminado em '\0'
  */
  char palavra[20] = "abracadabra";

  for(auto value : palavra) {
    cout << value << endl;
  }

  /**
   * std::string (como parte da biblioteca padrão)
  */
  std::string palavra2;
  palavra2 = "abracadabra";

  for(auto value : palavra2) {
    cout << value << endl;
  }

  return 0;
}