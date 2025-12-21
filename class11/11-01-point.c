#include <stdio.h>

/* define struct point here */

/* define point_newXY() here */

int main(int argc, char **argv)
{
    struct point p = point_newXY(3.0, 4.0);

    printf("%f,%f", p.x, p.y);
    putchar('\n');

    return 0;
}
