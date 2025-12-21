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

void reverse(char s[], int len)
{
    for (int i = 0; i < len / 2; ++i) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

int itos(int i, char s[])
{
    int len = 0;
    do {
        s[len++] = digitChar(i % 10);
        i /= 10;
    } while (i > 0);
    s[len] = '\0';
    reverse(s, len);
    return len;
}

int main(int argc, char *argv[])
{
    char s[1024];

    itos(    0, s);  printf("%s\n", s);
    itos(    1, s);  printf("%s\n", s);
    itos(   42, s);  printf("%s\n", s);
    itos(65535, s);  printf("%s\n", s);

    return 0;
}

