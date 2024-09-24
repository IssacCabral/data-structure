#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Student {
  int registration; // matricula
  char name[50]; // nome
  float finalAverage; // média final
} Student;

typedef struct StudentList {
  Student* data;
  int length; // tamanho atual
  int max_capacity; // capacidade máxima
} StudentList;

Student createStudent(int registration, char* name, float finalAverage) {
  Student newStudent;

  strcpy(newStudent.name, name);
  newStudent.registration = registration;
  newStudent.finalAverage = finalAverage;

  return newStudent;
}

StudentList* createStudentList(int max_capacity) {
  StudentList* studentList = (StudentList*) malloc(sizeof(StudentList));

  studentList->data = (Student*) malloc(sizeof(Student) * max_capacity);
  studentList->max_capacity = max_capacity;
  studentList->length = 0;
  
  return studentList;
}

void insert(StudentList* studentList, int registration, char* name, float finalAverage) {
  if (studentList->length == studentList->max_capacity) {
    printf("maximum capacity reached\n");
    return;
  }

  Student newStudent = createStudent(registration, name, finalAverage);
  studentList->data[studentList->length] = newStudent;
  studentList->length++;
}

bool removeStudent(StudentList* studentList, int registration) {
  for (int i = 0; i < studentList->length; i++) {
    if (studentList->data[i].registration == registration) {
      printf("Removendo Aluno: %s, Matrícula: %d\n", studentList->data[i].name, studentList->data[i].registration);

      for (int j = i; j < studentList->length - 1; j++) {
        studentList->data[j] = studentList->data[j + 1];
      }

      studentList->length--;

      return true;
    }
  }

  return false;
}

void swap(StudentList* studentList, int i, int j) {
  Student temp = studentList->data[i];
  studentList->data[i] = studentList->data[j];
  studentList->data[j] = temp;
}

int findMinorIndexFinalAverage(StudentList* studentList, int start, int length) {
  int minorIndex = start;

  for (int i = start + 1; i < length; i++) {
    Student student = studentList->data[i];
    if (student.finalAverage < studentList->data[minorIndex].finalAverage) {
      minorIndex = i;
    }
  }

  return minorIndex;
}

void selectionSortFinalAverage(StudentList* studentList, int start) {
  if (start >= studentList->length - 1) {
    return;
  }

  int minorIndex = findMinorIndexFinalAverage(studentList, start, studentList->length);

  if (minorIndex != start) {
    swap(studentList, start, minorIndex);
  }

  selectionSortFinalAverage(studentList, start + 1);
}

int findMinorIndexRegistration(StudentList* studentList, int start, int length) {
  int minorIndex = start;

  for (int i = start + 1; i < length; i++) {
    Student student = studentList->data[i];
    if (student.registration < studentList->data[minorIndex].registration) {
      minorIndex = i;
    }
  }

  return minorIndex;
}

void selectionSortRegistration(StudentList* studentList, int start) {
  if (start >= studentList->length - 1) {
    return;
  }

  int minorIndex = findMinorIndexRegistration(studentList, start, studentList->length);

  if (minorIndex != start) {
    swap(studentList, start, minorIndex);
  }

  selectionSortRegistration(studentList, start + 1);
}

void list(StudentList* studentList) {
  for (int i = 0; i < studentList->length; i++) {
    Student student = studentList->data[i];
    printf("Aluno: %s, Matrícula: %d, Média Final: %.2f\n", student.name, student.registration, student.finalAverage);
  }
}

Student findByRegistration(StudentList* studentList, int registration, int low, int hight) {
  if (low > hight) {
    Student notFound;
    notFound.registration = -1;
    return notFound;
  }

  int mid = low + (hight - low) / 2;

  if (studentList->data[mid].registration == registration) {
    return studentList->data[mid];
  }

  // buscar no lado esquerdo
  if (studentList->data[mid].registration > registration) {
    return findByRegistration(studentList, registration, low, mid - 1);
  }

  // buscar no lado direito
  return findByRegistration(studentList, registration, mid + 1, hight);
}

int main() {
  StudentList* studentList = createStudentList(10);

  insert(studentList, 4, "Maria Alencar", 10);
  insert(studentList, 2, "Pereira Mathias", 1.56);
  insert(studentList, 6, "Minato Usumaki", 5.78);
  insert(studentList, 1, "José Arimateia", 2.90);
  insert(studentList, 5, "Minouri", 2.91);
  insert(studentList, 3, "Melissa", 1.34);

  // list(studentList);

  // removeStudent(studentList, 1);
  // list(studentList);

  // selectionSortFinalAverage(studentList, 0);
  selectionSortRegistration(studentList, 0);
  // list(studentList);

  int registrationToFind = 0;
  Student student = findByRegistration(studentList, registrationToFind, 0, studentList->length - 1);

  if (student.registration != -1) {
    printf("Aluno encontrado: %s, Matrícula: %d, Média Final: %.2f\n", student.name, student.registration, student.finalAverage);
  } else {
    printf("Aluno com matrícula %d não encontrado.\n", registrationToFind);
  }

  free(studentList->data);
  free(studentList);

  return 0;
}