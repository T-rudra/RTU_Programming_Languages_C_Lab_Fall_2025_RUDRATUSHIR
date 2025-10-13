#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct {
  char name[MAX_NAME_LEN];
  int age;
  float gpa;
} Student;

void save_student_binary(const Student* s, const char* filename) {
  FILE* fp = fopen(filename, "wb");
  if (!fp) {
    printf("Error: Could not open %s for writing.\n", filename);
    return;
  }
  fwrite(s, sizeof(Student), 1, fp);
  fclose(fp);
  printf("Saving student in binary format...\n");
}

int load_student_binary(Student* s, const char* filename) {
  FILE* fp = fopen(filename, "rb");
  if (!fp) {
    printf("Error: Could not open %s for reading.\n", filename);
    return 0;
  }
  int read = fread(s, sizeof(Student), 1, fp);
  fclose(fp);
  printf("Loading student from binary file...\n");
  return read;
}

long get_file_size(const char* filename) {
  FILE* fp = fopen(filename, "rb");
  if (!fp) return -1;
  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);
  fclose(fp);
  return size;
}

int main(void) {
  Student s1;
  strcpy(s1.name, "Alice");
  s1.age = 21;
  s1.gpa = 3.75f;

  const char* filename = "src/struct.bin";
  save_student_binary(&s1, filename);

  Student loaded;
  if (load_student_binary(&loaded, filename)) {
    printf("Loaded student: %s, %d, GPA %.2f\n", loaded.name, loaded.age,
           loaded.gpa);
  } else {
    printf("Failed to load student.\n");
  }

  long size = get_file_size(filename);
  if (size >= 0) {
    printf("Binary file size: %ld bytes\n", size);
  } else {
    printf("Could not determine file size.\n");
  }
  return 0;
}
