#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("usage: %s n-points\n", argv[0]);
    return 1;
  }

  int n_points = atoi(argv[1]);
  int points_inside_circle = 0;

  srand(time(NULL));

  for (int i = 0; i < n_points; i++) {
    double x = ((double)rand() / RAND_MAX) * 2.0;
    double y = ((double)rand() / RAND_MAX) * 2.0;

    double dx = x - 1.0;
    double dy = y - 1.0;

    if ((dx * dx + dy * dy) < 1.0) {
      points_inside_circle++;
    }
  }

  double pi_estimate = 4.0 * points_inside_circle / n_points;

  printf("%d out of %d points inside the circle\n", points_inside_circle,
         n_points);
  printf("pi is approximately %.8f\n", pi_estimate);

  return 0;
}