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
    int start = -1;   // +m
    int count = -1;   // -n

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '+')
            start = atoi(argv[i] + 1);
        else if (argv[i][0] == '-')
            count = atoi(argv[i] + 1);
        else {
            printf("illegal argument\n");
            return 0;
        }
    }

    if (start != -1 && count != -1) {
        char line[LINEMAX];
        int curr = 1;

        while (getchars(line, sizeof(line)) >= 0) {
            if (curr >= start && curr < start + count)
                printf("%s\n", line);
            curr++;
        }
        return 0;
    }

    printf("Missing +m or -n option\n");
    return 0;
}
