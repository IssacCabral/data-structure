#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * * SAÍDA FICTÍCIA DO CÓDIGO
 * 
  Endereço da variável user:                     0x7fff39970cc0
  Endereço da propriedade name:                  0x7fff39970cc0
  Endereço da propriedade age:                   0x7fff39970cf4
  Endereço da propriedade address:               0x7fff39970cf8
  Endereço para o qual a propriedade address aponta: 0x55cde7c05470
  Endereço da propriedade houseNumber:           0x55cde7c05470
  Endereço da propriedade street:                0x55cde7c05474
  Endereço da variável address fora do user:     0x7fff39970c80
  Endereço para o qual a variável address aponta fora do user: 0x55cde7c05470
  Endereço da propriedade houseNumber fora do user: 0x55cde7c05470
  Endereço da propriedade street fora do user:   0x55cde7c05474 

 * * ESTRUTURA DE MEMÓRIA

  Memory (Stack):

  User (struct User)                    (Endereço base: 0x7fff39970cc0)
  -------------------------------------
  | name[0] ('I')                | (0x7fff39970cc0) 
  | name[1] ('s')                | (0x7fff39970cc1) 
  | ...                          | 
  | name[49] ('\0')              | (0x7fff39970cf3) 
  | age (27, 4 bytes)            | (0x7fff39970cf4) 
  | address (8 bytes, ponteiro)  | (0x7fff39970cf8)  <-- Armazena o endereço da struct `Address` na heap (0x55cde7c05470) 

  Memory (Heap):

  Address (struct Address)             (Endereço base: 0x55cde7c05470)
  -------------------------------------
  | houseNumber (12, 4 bytes)    | (0x55cde7c05470) 
  | street[0] ('R')              | (0x55cde7c05474) 
  | street[1] ('u')              | (0x55cde7c05475) 
  | ...                          | 
  | street[49] ('\0')            | (0x55cde7c054a7) 
  -------------------------------------
 */

typedef struct Address {
  int houseNumber;
  char street[50];
} Address;

typedef struct User {
  char name[50];
  int age;
  Address *address;
} User;

int main() {
  // Address address = {12, "Rua Francisco Almeida Pinheiro"};
  Address *address = malloc(sizeof(Address));

  address->houseNumber = 12;
  strcpy(address->street, "Rua Maria Almeida");

  User user = {"Issac", 27, address};

  printf("Endereço da variavel user: %p\n", &user);
  printf("Endereço da propriedade name: %p\n", &user.name);
  printf("Endereço da propriedade age: %p\n", &user.age);
  printf("Endereço da propriedade address: %p\n", &user.address);
  printf("Endereço para o qual a propriedade address aponta: %p\n", user.address);
  printf("Endereço da propriedade houseNumber: %p\n", &user.address->houseNumber);
  printf("Endereço da propriedade street: %p\n", &user.address->street);
  printf("Endereço da variavel address fora do user: %p\n", &address);
  printf("Endereço para o qual a variavel address aponta fora do user: %p\n", address);
  printf("Endereço da propriedade houseNumber fora do user: %p\n", &address->houseNumber);
  printf("Endereço da propriedade street fora do user: %p\n", &address->street);

  return 0;
}