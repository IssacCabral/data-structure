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

template<typename T>
class MyVector {
  private:
    const unsigned short INITIAL_CAPACITY = 2;
    
    unsigned int size;
    int capacity;
    
    T *elementList;

  public:
    MyVector() {
      size = 0;
      capacity = INITIAL_CAPACITY;
      elementList = new T[capacity];
    }

    ~MyVector() {
      delete[] elementList;
    }

    void add(T element) {
      if (size == capacity) {
        capacity *= 2;
        T *newElementList = new T[capacity];

        for(int i = 0; i < size; i++) {
          newElementList[i] = elementList[i];
        }

        delete[] elementList;
        elementList = newElementList;
      }

      elementList[size] = element;
      size++;
    }

    T* getAll() {
      return elementList;
    }

    optional<T> find(unsigned int index) {
      return index >= size ? nullopt : optional{elementList[index]};
    }

    bool remove(unsigned int index) {
      if(index >= size) {
        return false;
      }

      for(int i = index; i < size - 1; i++) {
        elementList[i] = elementList[i + 1];
      }

      size--;
      return true;
    }

    unsigned int length() {
      return size;
    }
};

int main() {
  MyVector<Contact> myVector;
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

        Contact *contactList = myVector.getAll();
        
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
