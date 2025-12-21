#include <stdio.h>

void reverse(char s[], int len) //swaps characters in the string, first with last, secong with second-last.
{
    for (int i = 0; i < len / 2; ++i) { //runs halfway to avoid undoing swaps
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;  //used later to flip the digits built in reverse order.
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

int itosnbwp(int i, char s[], int n, int b, int w, int p)
{
    int len = 0;

    if (n <= 0) return 0;  //if no capacity, quit immediately.

    // 1. store digits in reverse order (base b)
    do {
        if (len >= n - 1) break;
        s[len++] = digitChar(i % b); //%b gets the last digit in chosen base.digitchar converts it to the right character
        i /= b;//removes the digit. this makes digits to be stored backwards.
    } while (i > 0);//stop early if buffer nearly full

    // 2. pad with chosen character until width reached
    while (len < w && len < n - 1) {
        s[len++] = p;
    }

    // 3. terminate and reverse for correct order
    s[len] = '\0';
    reverse(s, len);
    return len;
}

int main(int argc, char *argv[])
{
    char s[1024];

    itosnbwp(    0, s, 1024,  2, 4, ' ');  printf("%s\n", s);
    itosnbwp(    1, s, 1024,  2, 4, '0');  printf("%s\n", s);
    itosnbwp(   42, s, 1024,  2, 4, ' ');  printf("%s\n", s);
    itosnbwp(   42, s, 1024,  8, 4, ' ');  printf("%s\n", s);
    itosnbwp(   42, s, 1024, 10, 4, '0');  printf("%s\n", s);
    itosnbwp(65535, s, 1024, 16, 4, '0');  printf("%s\n", s);

    return 0;
}
