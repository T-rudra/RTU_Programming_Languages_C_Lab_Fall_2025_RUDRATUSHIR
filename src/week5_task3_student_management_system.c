

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define DATA_FILE "students.txt"

typedef struct {
  char name[NAME_LEN];
  int id;
  float gpa;
} Student;

// Function prototypes
int load_students(Student arr[]);
void save_students(Student arr[], int count);
void add_student(Student arr[], int* count);
void list_students(Student arr[], int count);

int main(void) {
  Student students[MAX_STUDENTS];
  int count = 0;
  int choice;

  count = load_students(students);

  do {
    printf("\n=== Student Management System ===\n");
    printf("1. List students\n");
    printf("2. Add student\n");
    printf("3. Save and Exit\n");
    printf("Select an option: ");
    scanf("%d", &choice);
    getchar();  // clear newline

    switch (choice) {
      case 1:
        list_students(students, count);
        break;
      case 2:
        add_student(students, &count);
        break;
      case 3:
        save_students(students, count);
        printf("Data saved. Goodbye!\n");
        break;
      default:
        printf("Invalid option. Try again.\n");
    }
  } while (choice != 3);

  return 0;
}

int load_students(Student arr[]) {
  FILE* fp = fopen("src/" DATA_FILE, "r");
  int i = 0;
  if (!fp) {
    return 0;
  }
  while (i < MAX_STUDENTS &&
         fscanf(fp, "%49s %d %f", arr[i].name, &arr[i].id, &arr[i].gpa) == 3) {
    i++;
  }
  fclose(fp);
  return i;
}

void save_students(Student arr[], int count) {
  FILE* fp = fopen("src/" DATA_FILE, "w");
  if (!fp) {
    printf("Error: Could not open file for saving.\n");
    return;
  }
  for (int i = 0; i < count; i++) {
    fprintf(fp, "%s %d %.2f\n", arr[i].name, arr[i].id, arr[i].gpa);
  }
  fclose(fp);
}

void add_student(Student arr[], int* count) {
  if (*count >= MAX_STUDENTS) {
    printf("Cannot add more students.\n");
    return;
  }
  Student s;
  printf("Enter name: ");
  scanf("%49s", s.name);
  printf("Enter ID: ");
  scanf("%d", &s.id);
  printf("Enter GPA: ");
  scanf("%f", &s.gpa);
  arr[*count] = s;
  (*count)++;
  printf("Student added successfully!\n");
}

void list_students(Student arr[], int count) {
  if (count == 0) {
    printf("No students found.\n");
    return;
  }
  printf("\n%-6s %-15s %-5s\n", "ID", "Name", "GPA");
  for (int i = 0; i < count; i++) {
    printf("%-6d %-15s %-5.2f\n", arr[i].id, arr[i].name, arr[i].gpa);
  }
}
