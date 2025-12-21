#include <stdio.h>

unsigned int setBits(unsigned int i, int p, int n, int b)
{
    if (n <= 0 || p < 0) return i;

    unsigned int width = sizeof(unsigned int) * 8u;
    if ((unsigned int)p >= width) return i;

    unsigned int mask = ((1u << n) - 1u);

    unsigned int shift = (unsigned int)p;
    unsigned int positioned_mask = mask << shift;
    i &= ~positioned_mask;

    unsigned int bmask = ((unsigned int)b) & mask;
    i |= (bmask << shift);

    return i;
}

int main()
{
    unsigned int i = 0b10110011100011110000111110000011;

    printf("%u\n", i = setBits(i,  2, 30,  1)); //   7
    printf("%u\n", i = setBits(i,  6,  2,  7)); // 199
    printf("%u\n", i = setBits(i,  2,  4, 15)); // 255

    return 0;
}
