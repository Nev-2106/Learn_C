#include <stdio.h>

unsigned int setBit(unsigned int i, int p)
{
    return i | (1u << p);
}

int main()
{
    unsigned int i = 0;

    printf("%u\n", i = setBit(i, 1));
    printf("%u\n", i = setBit(i, 3));
    printf("%u\n", i = setBit(i, 5));

    return 0;
}
