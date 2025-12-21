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

int itor(int i, char s[])
{
    int j = 0;
    do {
        s[j++] = digitChar(i % 10);
        i /= 10;
    } while (i > 0);
    s[j] = '\0';
    return j;
}

int main(int argc, char *argv[])
{
    char s[1024];

    itor(    0, s);  printf("%s\n", s);
    itor(    1, s);  printf("%s\n", s);
    itor(   42, s);  printf("%s\n", s);
    itor(65535, s);  printf("%s\n", s);

    return 0;
}
