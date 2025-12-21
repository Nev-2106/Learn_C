#include <stdio.h>
#include <math.h>

struct point {
    double x;
    double y;
};

struct point point_create(double r, double a) {
    struct point p;
    p.x = r * cos(a);
    p.y = r * sin(a);
    return p;
}

double point_a(struct point p) {
    return atan2(p.y, p.x);
}

double point_r(struct point p) {
    return sqrt(p.x * p.x + p.y * p.y);
}

void point_printRA(struct point p) {
    printf("r = %.f, angle = %f radians (%.f degrees)\n", 
           point_r(p), point_a(p), point_a(p) * 180 / M_PI);
}

void point_print(struct point p) {
    printf("(%.2f, %.2f)\n", p.x, p.y);
}

int main(void) {
    struct point p1 = point_create(5.0, M_PI / 4);
    
    printf("Point 1 (rectangular): ");
    point_print(p1);
    printf("Point 1 (polar): ");
    point_printRA(p1);
    printf("\n");
    
    return 0;
}