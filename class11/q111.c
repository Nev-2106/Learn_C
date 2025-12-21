#include <stdio.h>

struct point {
    double x, y;
};

struct point point_newXY(double x, double y) {
    struct point p;  //creates object, values stored inside, returning a struct is allowed in C	x
    p.x = x;
    p.y = y;
    return p;
}

int main(int argc, char **argv)  //main uses it to printthe numbers
{
    struct point p = point_newXY(3.0, 4.0);
    printf("%f,%f", p.x, p.y);
    putchar('\n');
    return 0;
}
