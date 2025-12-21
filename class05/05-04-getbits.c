#include <stdio.h>

unsigned int getBits(unsigned int i, int p, int n)
{
    return (i >> p) & ~(~0u << n);
}

int main()
{
    unsigned int i = 0b10110011100011110000111110000011;

    printf("%u\n", getBits(i,  0, 8));
    printf("%u\n", getBits(i, 16, 8));
    printf("%u\n", getBits(i, 28, 4));

    return 0;
}
