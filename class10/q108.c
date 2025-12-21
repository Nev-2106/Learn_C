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
    int n = 10;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {     //argument must start with -, convert number after -
            n = atoi(argv[i] + 1);
            if (n < 0) {
                printf("illegal argument\n");//no negative
                return 0;
            }
        } else {
            printf("illegal argument\n");
            return 0;
        }
    }

    char line[LINEMAX];
    char **lines = malloc(sizeof(*lines) * n);//allocates pointer array of size n.
    int index = 0;

    while (getchars(line, sizeof(line)) >= 0) {
        if (index >= n)
            free(lines[index % n]);
        lines[index % n] = strdup(line);
        index++;
    }

    for (int i = index - n; i < index; i++) {
        if (i >= 0) {
            printf("%s\n", lines[i % n]);
            free(lines[i % n]);
        }
    }

    free(lines);
    return 0;
}
