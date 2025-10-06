/*
 * week4_3_struct_database.c
 * Author: [Rudra Tushir]
 * Student ID: [231ADB234]
 * Description:
 *   Simple in-memory "database" using an array of structs.
 *   Students will use malloc to allocate space for multiple Student records,
 *   then input, display, and possibly search the data.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
  char name[50];
  int id;
  float grade;
};

int main(void) {
  int n;
  struct Student* students = NULL;

  printf("Enter number of students: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Invalid number.\n");
    return 1;
  }

  students = (struct Student*)malloc(n * sizeof(struct Student));
  if (students == NULL) {
    printf("Error: Memory allocation failed.\n");
    return 1;
  }

  for (int i = 0; i < n; i++) {
    printf("Enter data for student %d (name id grade): ", i + 1);
    if (scanf("%49s %d %f", students[i].name, &students[i].id,
              &students[i].grade) != 3) {
      printf("Invalid input.\n");
      free(students);
      return 1;
    }
  }

  printf("\n%-6s %-10s %-5s\n", "ID", "Name", "Grade");
  for (int i = 0; i < n; i++) {
    printf("%-6d %-10s %-5.1f\n", students[i].id, students[i].name,
           students[i].grade);
  }

  free(students);
  return 0;
}
