#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
  char registration[50];
  char name[50];
  float finalAverage;
} Student;

typedef struct StudentList {
  Student* data;
  int length;
  int max_capacity;
} StudentList;

Student createStudent(char* registration, char* name, float finalAverage) {
  Student newStudent;

  strcpy(newStudent.registration, registration);
  strcpy(newStudent.name, name);
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

void insert(StudentList* studentList,char* registration, char* name, float finalAverage) {
  if (studentList->length == studentList->max_capacity) {
    printf("maximum capacity reached");
    return;
  }

  Student newStudent = createStudent(registration, name, finalAverage);
  studentList->data[studentList->length] = newStudent;\
  studentList->length++;
}

// void remove() {

// }

void list(StudentList* studentList) {
  for (int i = 0; i < studentList->length; i++) {
    Student student = studentList->data[i];
    printf("Aluno: %s, Matrícula: %s, Média Final: %.2f\n", student.name, student.registration, student.finalAverage);
  }
}

int main() {
  StudentList* studentList = createStudentList(10);

  insert(studentList, "001", "Maria Alencar", 7.89);
  insert(studentList, "002", "Pereira Mathias", 7.89);
  insert(studentList, "003", "Minato Usumaki", 7.89);

  list(studentList);

  return 0;
}