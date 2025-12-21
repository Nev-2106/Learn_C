#include <stdio.h>

char *strcopy(char *s, char *t)
{
    char *ret = s;
    while ((*s++ = *t++) != '\0')
        ;
    return ret;
}

int main()
{
    char s[100] = "overwrite", *t = "me!";
    printf("%s\n", strcopy(s, t));
    return 0;
}
