#include <stdio.h>

int strlength(char *s)
{
char *start = s;        
while (*s != '\0') {     
    s++;
}
return s - start;   
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
