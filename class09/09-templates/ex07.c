#include <stdio.h>

int strlength(char *s)
{
    char *start = s;        
    while (*s != '\0') {     
    s++;
    }
return s - start; 
}

void swapchars(char *c, char *d)
{
    char temp = *c;
    *c = *d;
    *d = temp;
}

char *reverse(char *s)
{
    int len = strlength(s);
    for (int i = 0; i < len / 2; i++) {
        swapchars(&s[i], &s[len - 1 - i]);
    }
    return s;
}

int main()
{
    char a[100] = "";
    char b[100] = "b";
    char c[100] = "bc";
    char d[100] = "bcd";
    char s[100] = "peter piper picked a peck";
    printf("%s\n", reverse(a));
    printf("%s\n", reverse(b));
    printf("%s\n", reverse(c));
    printf("%s\n", reverse(d));
    printf("%s\n", reverse(s));
    return 0;
}
