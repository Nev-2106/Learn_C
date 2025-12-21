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

int main()
{
    printf("%d\n", strlength("hello, world")); // 12
    char s[] = "hello, world";
    printf("%d\n", strlength(s));              // 12
    char *p = s;
    printf("%d\n", strlength(p));              // 12
    return 0;
}
