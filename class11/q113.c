#include <stdio.h>

struct point {
    double x, y;
};

struct point point_newXY(double x, double y) {
    struct point p = { x, y };
    return p;   //instead of printf 100 times we just use return instead
}

double point_x(struct point p) { return p.x; }
double point_y(struct point p) { return p.y; }

struct point point_printXY(struct point p) {
    printf("%f,%f", p.x, p.y);
    return p;
}

int main(int argc, char **argv)
{
    struct point p = point_newXY(3.0, 4.0);
    point_printXY(p);  //the point is to call this
    putchar('\n');
    return 0;
}
