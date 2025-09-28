
int sum_to_n(int n) {
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += i;
  }
  return sum;
}

int main() {
  int n;
  printf("Enter a positive integer n: ");
  if (scanf("%d", &n) != 1) {
    printf("Invalid input.\n");
    return 1;
  }
  if (n < 1) {
    printf("Error: n must be >= 1.\n");
    return 1;
  }
  int result = sum_to_n(n);
  printf("Sum of 1 to %d is %d\n", n, result);
  return 0;
}
