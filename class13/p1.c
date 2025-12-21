#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // 1. Arg parsing and validation
  if (argc != 2) {
    printf("usage: %s max-prime\n", argv[0]);
    return 0; // The example shows usage printing but no error code specified,
              // using 0 or 1
  }

  int n = atoi(argv[1]);

  if (n < 2) {
    printf("%s: max-prime %d is too small (must be at least 2)\n", argv[0], n);
    return 0;
  }

  // 2. Sieve Array Initialization
  // We need indices up to n, so size n+1
  // p[i] is true if i is prime.
  bool *p = malloc((n + 1) * sizeof(bool));
  if (p == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return 1;
  }

  // Initialize all to true
  for (int i = 2; i <= n; i++) {
    p[i] = true;
  }

  // 3. Sieve Logic
  // Optimization: loop i from 2 to sqrt(n).
  // Written as i*i <= n to avoid sqrt() function and floating point.
  for (int i = 2; i * i <= n; i++) {
    if (p[i]) {
      for (int j = i * i; j <= n; j += i) {
        p[j] = false;
      }
    }
  }

  // 4. Print results
  for (int i = 2; i <= n; i++) {
    if (p[i]) {
      printf("%d ", i);
    }
  }
  printf("\n");

  free(p);
  return 0;
}
