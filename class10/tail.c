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

int main(int argc, char **argv)
{
    char   line[LINEMAX];
    char  *lines[10];

    int index = 0;
    while (getchars(line, sizeof(line)) >= 0) {
	if (index >= 10) free(lines[index % 10]);
	lines[index++ % 10] = strdup(line); // this must be free()d
    }
    for (int i = index - 10;  i < index;  ++i) {
	if (i >= 0) { // entry exists in array
	    printf("%s\n", lines[i % 10]);
	    free(lines[i % 10]);
	}
    }

    return 0;
}
