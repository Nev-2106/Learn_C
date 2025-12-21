#include <stdio.h>

int strlength(char *s)
{
    char *start = s;        
    while (*s != '\0') {     
    s++;
    }
return s - start; 
}

#define MAX(A, B) ((A) > (B) ? (A) : (B))

int strmax(char *s, char *t)
{
    int ls = strlength(s);
    int lt = strlength(t);
    return MAX(ls, lt);
}

void swapchars(char *c, char *d)
{
    char temp = *c;
    *c = *d;
    *d = temp;
}

void swapstrings(char *s, char *t)
{
    int len = strmax(s, t);
    for (int i = 0; i < len; i++) {
        swapchars(&s[i], &t[i]);
    }
}

int main()
{
    char s[100] = "the first string";
    char t[100] = "another string, a bit longer";
    printf("%s\n%s\n", s, t);
    swapstrings(s, t);
    printf("%s\n%s\n", s, t);

    return 0;
}
