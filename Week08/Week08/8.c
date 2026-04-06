#include <stdio.h>

#define SWAP(T, X, Y) do { \
    T Temp = (X);         \
    (X) = (Y);             \
    (Y) = Temp;            \
} while(0)


int main() {
    int i = 42, j = 666, k = 123;
    if (i > j) SWAP(int, i, j);
    else       SWAP(int, i, k);
    printf("%d %d %d\n", i, j, k);
return 0; }