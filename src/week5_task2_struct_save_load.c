#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct {
  char name[MAX_NAME_LEN];
  int age;
  float gpa;
} Student;

void save_students(Student* arr, int n, const char* filename);
int load_students(Student* arr, int max_n, const char* filename);

int main(void) {
  int n;
  printf("Enter number of students: ");
  if (scanf("%d", &n) != 1 || n < 1) {
    printf("Invalid number.\n");
    return 1;
  }
  Student* arr = malloc(n * sizeof(Student));
  if (!arr) {
    printf("Memory allocation failed.\n");
    return 1;
  }
  for (int i = 0; i < n; i++) {
    printf("Enter name age GPA for student %d: ", i + 1);
    if (scanf("%49s %d %f", arr[i].name, &arr[i].age, &arr[i].gpa) != 3) {
      printf("Invalid input.\n");
      free(arr);
      return 1;
    }
  }

  const char* filename = "src/struct.txt";
  printf("Saving students to file...\n");
  save_students(arr, n, filename);

  printf("Loading students from file...\n");
  Student* loaded = malloc(n * sizeof(Student));
  if (!loaded) {
    printf("Memory allocation failed.\n");
    free(arr);
    return 1;
  }
  int loaded_n = load_students(loaded, n, filename);
  for (int i = 0; i < loaded_n; i++) {
    printf("Loaded student: %s, %d, GPA %.2f\n", loaded[i].name, loaded[i].age,
           loaded[i].gpa);
  }
  free(arr);
  free(loaded);
  return 0;
}

void save_students(Student* arr, int n, const char* filename) {
  FILE* fp = fopen(filename, "w");
  if (!fp) {
    printf("Error: Could not open %s for writing.\n", filename);
    return;
  }
  for (int i = 0; i < n; i++) {
    fprintf(fp, "%s %d %.2f\n", arr[i].name, arr[i].age, arr[i].gpa);
  }
  fclose(fp);
}

int load_students(Student* arr, int max_n, const char* filename) {
  FILE* fp = fopen(filename, "r");
  if (!fp) {
    printf("Error: Could not open %s for reading.\n", filename);
    return 0;
  }
  int i = 0;
  while (i < max_n &&
         fscanf(fp, "%49s %d %f", arr[i].name, &arr[i].age, &arr[i].gpa) == 3) {
    i++;
  }
  fclose(fp);
  return i;
}
