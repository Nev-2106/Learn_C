#include <stdio.h>
#include <stdlib.h>

int getchars(char *s, int limit)
{
    int c, i;
    i = 0;
    while (--limit > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int strlength(char *s)
{
    int n;
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}

char *strcopy(char *s, char *t)
{
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
    return s;
}

char *strduplicate(char *string)
{
    char *p;
    p = (char *) malloc(strlength(string) + 1);
    if (p != NULL)
        strcopy(p, string);
    return p;
}

#define LINEMAX  1000
#define LINESMAX 1000

int main()
{
    char line[LINEMAX];
    char *lines[LINESMAX];
    int nlines= 0;
    while (nlines < LINESMAX && getchars(line, sizeof(line)) >= 0)
        lines[nlines++] = strduplicate(line);
    while (nlines-- > 0)
        printf("%s\n", lines[nlines]);
    return 0;
}
