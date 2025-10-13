#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE* fp;
  char filename[100] = "src/data.txt";
  char line[256];

  printf("Writing lines to %s...\n", filename);
  fp = fopen(filename, "w");
  if (fp == NULL) {
    printf("Error: Could not open %s for writing.\n", filename);
    return 1;
  }
  fprintf(fp, "Hello, I am Rudra\n");
  fprintf(fp, "I study at Riga Technical University\n");
  fprintf(fp, "I love programming in C\n");
  fclose(fp);

  printf("Reading contents:\n");
  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error: Could not open %s for reading.\n", filename);
    return 1;
  }
  while (fgets(line, sizeof(line), fp) != NULL) {
    printf("%s", line);
  }
  fclose(fp);

  return 0;
}
