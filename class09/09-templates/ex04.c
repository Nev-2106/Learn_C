#include <stdio.h>

int strlength(char *s)
{
    char *start = s;        
    while (*s != '\0') {     
        s++;
    }
    return s - start;  
}

char *strcopy(char *s, char *t)
{
    char *ret = s;
    while ((*s++ = *t++) != '\0')
        ;
    return ret;
}

char *strappend(char *s, char *t)
{
    char *p = s;
    while (*p != '\0')
        p++;
    strcopy(p, t);
    return s;
}

int main()
{
    char s[100] = "append ", *t = "me!";
    printf("%s\n", strappend(s, t));
    return 0;
}
