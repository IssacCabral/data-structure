#include <iostream>
#include <optional>

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
    
    unsigned int size;
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

    Contact* listContacts() {
      return contactList;
    }

    optional<Contact> find(unsigned int index) {
      return index >= size ? nullopt : optional{contactList[index]};
    }

    bool remove(unsigned int index) {
      if(index >= size) {
        return false;
      }

      for(int i = index; i < size - 1; i++) {
        contactList[i] = contactList[i + 1];
      }

      size--;
      return true;
    }

    unsigned int length() {
      return size;
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
    cout << "4 - Excluir um contato\n";
    cout << "0 - Sair do programa\n";

    cin >> option;
    
    switch(option) {
      case 1: {
        clearScreen();
        
        Contact contact;
        cin >> contact.name;
        cin >> contact.number;    
        
        myVector.add(contact);
        break;        
      }

      case 2: {
        clearScreen();

        if(myVector.length() == 0) {
          cout << "Lista de contatos vazia\n";
          awaitUser();
          break;
        } 

        Contact *contactList = myVector.listContacts();
        
        for (int i = 0; i < myVector.length(); i++) {
          Contact contact = contactList[i];
          cout << "Contato[" << i << "]: Nome: " << contact.name << " Numero: " << contact.number << endl;
        }        

        awaitUser();
        break;        
      }

      case 3: {
        clearScreen();
        
        if(myVector.length() == 0) {
          cout << "Lista de contatos vazia\n";
          awaitUser();
          break;
        } 

        unsigned int index;
        cin >> index;

        optional<Contact> contact = myVector.find(index);

        if(contact != nullopt) {
          cout << "Nome: " << contact.value().name << " Numero: " << contact.value().number << endl;
        } else {
          cout << "Contato não encontrado" << endl;
        }

        awaitUser();
        break;
      }

      case 4: {
        clearScreen();

        if(myVector.length() == 0) {
          cout << "Lista de contatos vazia\n";
          awaitUser();
          break;
        }         

        unsigned int index;
        cin >> index;

        myVector.remove(index);

        break;
      }
    
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
