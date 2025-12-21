#include <stdio.h>

int digitChar(int i)
{
    if (i >= 0 && i <= 9)
        return '0' + i;
    else if (i >= 10 && i <= 35)
        return 'A' + (i - 10);
    else
        return '?';
}

void iprint(int i)
{
    do {
        int d = i % 10;
        putchar(digitChar(d));
        i /= 10;
    } while (i > 0);
    putchar('\n');
}

int main(int argc, char *argv[])
{
    iprint(    0);
    iprint(    1);
    iprint(   42);
    iprint(65535);

    return 0;
}

