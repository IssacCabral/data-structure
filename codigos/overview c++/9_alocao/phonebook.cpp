#include <iostream>

// encontrar um contato

using namespace std;

struct Contact {
  string name;
  int number;
};

void clearScreen() {
  system("clear");
}

void awaitUser() {
  cout << "Pressione qualquer tecla para continuar...";
  cin.ignore(); 
  cin.get(); 
}

void addContact(Contact *&contactList, int *size, int *capacity) {
  if (*size == *capacity) {
    *capacity *= 2;
    Contact *newContactList = new Contact[*capacity];

    for(int i = 0; i < *size; i++) {
      newContactList[i] = contactList[i];
    }

    delete[] contactList;
    contactList = newContactList;
  }

  cout << "Digite o nome do contato: ";
  cin >> contactList[*size].name;
  cout << "Digite o número do contato: ";
  cin >> contactList[*size].number;

  (*size)++;

  cout << "Contato adicionado com sucesso.\n";
}

void listContacts(Contact *contactList, int size) {
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

void findByName(Contact *contactList, int size) {
  if(size == 0) {
    cout << "Lista de contatos vazia\n";
    awaitUser();
  } else {
    string name;

    cout << "Digite o contato que deseja buscar: " << endl;
    cin >> name;

    bool contactWasFound = false;

    for (int i = 0; i < size; i++) {
      if(contactList[i].name == name) {
        contactWasFound = true;

        cout << "Contato Encontrado:\n";
        cout << "Nome: " << contactList[i].name << endl;
        cout << "Numero: " << contactList[i].number << endl;

        awaitUser();
      }
    }

    if(!contactWasFound) {
      cout << "Contato não encontrado...\n";
      awaitUser();
    }
  }  
}

int main() {
  const unsigned short INITIAL_CAPACITY = 2;

  int size = 0;
  int capacity = INITIAL_CAPACITY;

  Contact *contactList = new Contact[capacity];

  int option;
  do {
    clearScreen();

    cout << "Escolha uma opção...\n";
    cout << "1 - Adicionar novo contato\n";
    cout << "2 - Listar todos os contatos\n";
    cout << "3 - Encontrar um contato\n";
    cout << "0 - Sair do programa\n";

    cin >> option;

    switch(option) {
      case 1:
        clearScreen();
        addContact(contactList, &size, &capacity);
        break;
      case 2:
        clearScreen();
        listContacts(contactList, size);
        break;
      case 3:
        clearScreen();
        findByName(contactList, size);
        break;
      case 0:
        cout << "Saindo do programa...\n";
        break;
      default:
        cout << "Opção inválida\n";
        break;
    }

  } while(option != 0);

  delete[] contactList;

  return 0;
}