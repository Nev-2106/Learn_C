#include <stdio.h>

int strlength(char *s)
{
    int count = 0;
    while (*s != '\0') {
        count++;
        s++;
    }
    return count;
}

#define MAX(A, B)	((A) > (B) ? (A) : (B))

int strmax(char *s, char *t)
{
    int ls = strlength(s);
    int lt = strlength(t);
    return MAX(ls, lt);
}

int main()
{
    printf("%d\n", strmax("", ""));
    printf("%d\n", strmax("", "abc"));
    printf("%d\n", strmax("abc", ""));
    printf("%d\n", strmax("abc", "abc"));
    printf("%d\n", strmax("abcdef", "abc"));
    printf("%d\n", strmax("abc", "abcdefghi"));
    return 0;
}
