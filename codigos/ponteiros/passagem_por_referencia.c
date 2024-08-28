#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct User {
  char name[50];
  int age;
} User;

void foo(User *user) {
  printf("Na func... Endereço de memória de user: %p\n", &user);
  printf("Na func... Endereço de memória onde user está apontando: %p\n", user);
}

int main() {
  User *user = malloc(sizeof(User));

  if (user == NULL) {
    printf("Falha de alocação");
    exit(1);
  }

  strcpy(user->name, "Josefa");
  user->age = 99;

  printf("Na main... Endereço de memória de user: %p\n", &user);
  printf("Na main... Endereço de memória onde user está apontando: %p\n", user);

  foo(user);

  return 0;
}