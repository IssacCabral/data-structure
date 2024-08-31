#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  User user = {"Issac", 27, address};

  printUser(user);

  return 0;
}