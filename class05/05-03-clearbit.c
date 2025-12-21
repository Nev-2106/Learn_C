#include <stdio.h>

unsigned int clearBit(unsigned int i, int p)
{
    return i & ~(1u << p);
}

int main()
{
    unsigned int i = 62;

    printf("%u\n", i = clearBit(i, 0));
    printf("%u\n", i = clearBit(i, 2));
    printf("%u\n", i = clearBit(i, 4));

    return 0;
}
