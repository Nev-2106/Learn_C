#include <stdio.h>
#include <math.h>

/* define struct point, point_newXY(), point_[xyr](), point_printXY() here */

int main(int argc, char **argv)
{
    struct point p = point_newXY(3, 4);

    point_printXY(p);
    putchar('\n');

    printf("%f\n", point_r(p));

    return 0;
}
