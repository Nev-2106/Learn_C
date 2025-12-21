#include <stdio.h>

struct point {
    int x;
    int y;
};

struct rectangle {
    struct point origin;
    struct point corner;
};

struct rectangle rectangle_new(struct point origin, struct point corner) {
    struct rectangle r;
    r.origin = origin;
    r.corner = corner;
    return r;
}

struct rectangle *rectangle_println(struct rectangle *r) {
    printf("Rectangle: origin(%d, %d), corner(%d, %d)\n", 
           r->origin.x, r->origin.y, r->corner.x, r->corner.y);
    return r;
}

int rectangle_includes(struct rectangle *r, struct point *p) {
    if (p->x >= r->origin.x && p->x < r->corner.x &&
        p->y >= r->origin.y && p->y < r->corner.y) {
        return 1;
    }
    return 0;
}

int main(void) {
    struct point p1 = {0, 0};
    struct point p2 = {10, 10};
    struct rectangle rect = rectangle_new(p1, p2);
    rectangle_println(&rect);
    struct point test1 = {5, 12};
    printf("Point (5, 5) inside: %d\n", rectangle_includes(&rect, &test1));
    return 0;
}