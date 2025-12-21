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

struct point point_newRA(double r, double a) {
    double rad = (a / 180.0) * M_PI;

    struct point p;
    p.x = r * cos(rad);  //angle cnversion
    p.y = r * sin(rad);
    return p;     //return struct for direct consistency with earlier programs
}

int main(int argc, char **argv)
{
    struct point p = point_newRA(5, 53.13);
    point_printXY(p);
    putchar('\n');
    return 0;
}
