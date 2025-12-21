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

int main(int argc, char *argv[])
{
    for (int i = 0;  i < 40;  ++i)
        putchar(digitChar(i));
    putchar('\n');

    return 0;
}
