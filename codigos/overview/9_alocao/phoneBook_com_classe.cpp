#include <iostream>

using namespace std;

struct Contact {
  string name;
  string number;
};

void clearScreen() {
  system("clear");
}

void awaitUser() {
  cout << "Pressione qualquer tecla para continuar...";
  cin.ignore(); 
  cin.get(); 
}

class MyVector {
  private:
    const unsigned short INITIAL_CAPACITY = 2;
    
    int size;
    int capacity;
    
    Contact *contactList;

  public:
    MyVector() {
      size = 0;
      capacity = INITIAL_CAPACITY;
      contactList = new Contact[capacity];
    }

    void add(Contact contact) {
      if (size == capacity) {
        capacity *= 2;
        Contact *newContactList = new Contact[capacity];

        for(int i = 0; i < size; i++) {
          newContactList[i] = contactList[i];
        }

        delete[] contactList;
        contactList = newContactList;
      }

      contactList[size] = contact;
      size++;
    }

    void listContacts() {
      if(size == 0) {
        cout << "Lista de contatos vazia\n";
      } else {
        for (int i = 0; i < size; i++) {
          Contact contact = contactList[i];
          cout << "Contato[" << i << "]: Nome: " << contact.name << " Numero: " << contact.number << endl;
        }
      }
      awaitUser();
    }

    
};

int main() {
  MyVector myVector;
  int option;

  do {
    clearScreen();

    cout << "Escolha uma opção...\n";
    cout << "1 - Adicionar novo contato\n";
    cout << "2 - Listar todos os contatos\n";
    cout << "3 - Encontrar um contato\n";
    cout << "0 - Sair do programa\n";

    cin >> option;
    Contact contact;

    switch(option) {
      case 1:
        clearScreen();
        
        cin >> contact.name;
        cin >> contact.number;    
  
        myVector.add(contact);
        break;
      case 2:
        clearScreen();

        myVector.listContacts();

        break;
      case 3:
        clearScreen();
        break;
      case 0:
        cout << "Saindo do programa...\n";
        break;
      default:
        cout << "Opção inválida\n";
        break;
    }

  } while(option != 0);

  return 0;
}