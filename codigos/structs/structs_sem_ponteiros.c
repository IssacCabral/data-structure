#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 
 * Memory (Stack):

    User (User)
    ------------------
    | name[0]                 | (0x7fff39970cc0) 
    | name[1]                 | 
    | ...                     | 
    | name[49]                | (0x7fff39970cf3) 
    | age (4 bytes)           | (0x7fff39970cf4) 
    | address (54 bytes)      | (0x7fff39970cf8) 
    |-------------------------|
    | houseNumber (4 bytes)   | (0x7fff39970cf8) 
    | street[0]               | 
    | street[1]               | 
    | ...                     | 
    | street[49]              | (0x7fff39970d3f) 
    ------------------
 */

typedef struct Address {
  int houseNumber;
  char street[50];
} Address;

typedef struct User {
  char name[50];
  int age;
  Address address;
} User;

void printUser(User user) {
  printf("Name: %s, age: %d\nStreet: %s, houseNumber: %d\n", user.name, user.age, user.address.street, user.address.houseNumber);
}

int main() {
  Address address = {2020, "Avenida Francisco Almeida Pinheiro"};
  // ? aqui abaixo, address é uma cópia da variável address, por isso que o endereço de memoria de address, é diferente
  // ? do endereço de memória de user.address
  // ? conclusão: &user.address != &address 
  User user = {"Issac", 27, address}; 

  printf("Endereço da variavel user: %p\n", &user);
  printf("Endereço da propriedade name: %p\n", &user.name);
  printf("Endereço da propriedade age: %p\n", &user.age);
  printf("Endereço da propriedade address: %p\n", &user.address);
  printf("Endereço da propriedade houseNumber: %p\n", &user.address.houseNumber);
  printf("Endereço da propriedade street: %p\n", &user.address.street);
  printf("Endereço da variavel address fora do user: %p\n", &address);
  printf("Endereço da propriedade houseNumber fora do user: %p\n", &address.houseNumber);
  printf("Endereço da propriedade street fora do user: %p\n", &address.street);

  // printUser(user);

  return 0;
}