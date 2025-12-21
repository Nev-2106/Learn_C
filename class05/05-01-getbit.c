#include <stdio.h>

unsigned int getBit(unsigned int i, int p)
{
    return (i >> p) & 1u;
}

int main()
{
    unsigned int i = 0b10110011100011110000111110000011;

    for (int n = 0;  n < 16;  ++n)
        printf("%u", getBit(i, n));

    return 0;
}
