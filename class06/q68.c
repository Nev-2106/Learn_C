#include <stdio.h>

void reverse(char s[], int len)
{
    for (int i = 0; i < len / 2; ++i) {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

int digitChar(int i)
{
    if (i >= 0 && i <= 9)
        return '0' + i;
    else if (i >= 10 && i <= 35)
        return 'A' + (i - 10);
    else
        return '?';
}

int itosnbw(int i, char s[], int n, int b, int w)
{
    int len = 0;

    if (n <= 0) return 0;


    do {
        if (len >= n - 1) break;
        s[len++] = digitChar(i % b);
        i /= b;
    } while (i > 0);


    while (len < w && len < n - 1) {
        s[len++] = ' ';
    }

    s[len] = '\0';
    reverse(s, len);
    return len;
}

int main(int argc, char *argv[])
{
    char s[1024];

    itosnbw(    0, s, 1024,  2, 4);  printf("%s\n", s);
    itosnbw(    1, s, 1024,  2, 4);  printf("%s\n", s);
    itosnbw(   42, s, 1024,  2, 4);  printf("%s\n", s);
    itosnbw(   42, s, 1024,  8, 4);  printf("%s\n", s);
    itosnbw(   42, s, 1024, 10, 4);  printf("%s\n", s);
    itosnbw(65535, s, 1024, 16, 4);  printf("%s\n", s);

    return 0;
}
