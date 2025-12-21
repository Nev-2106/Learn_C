#include <stdio.h>
#include <math.h>

struct point {
    double x, y;
};

struct point point_newXY(double x, double y) {
    struct point p = { x, y };
    return p;
}

struct point point_printXY(struct point p) {
    printf("%f,%f", p.x, p.y);
    return p;
}

double point_r(struct point p) {
    return sqrt(p.x * p.x + p.y * p.y);
}

int main(int argc, char **argv)
{
    struct point p = point_newXY(3, 4);

    point_printXY(p);
    putchar('\n');

    printf("%f\n", point_r(p));
    return 0;
}
