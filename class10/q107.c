#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getchars(char *s, int limit)
{
    int i = 0, c;
    while (i < limit - 1 && EOF != (c = getchar()) && c != '\n')
        s[i++] = c;
    if (EOF == c && i == 0) return -1;
    s[i] = '\0';
    return i;
}

#define LINEMAX 1024
#define NLINES  10   // fixed, but memory must be allocated dynamically

int main(int argc, char **argv)
{
    char line[LINEMAX];
    char **lines = malloc(sizeof(*lines) * NLINES);  //allocates space for 10 pointers, before:char*lines[10], now:dynamic allocation
    int index = 0;

    while (getchars(line, sizeof(line)) >= 0) {
        if (index >= NLINES)
            free(lines[index % NLINES]);//buffer wraps around, free old entry
        lines[index % NLINES] = strdup(line);//store a copy of the new line, index%10 creates a circular buffer.0to10,10to0
        index++;
    }

    for (int i = index - NLINES; i < index; i++) {
        if (i >= 0) {
            printf("%s\n", lines[i % NLINES]);
            free(lines[i % NLINES]);
        }
    }

    free(lines);
    return 0;
}
