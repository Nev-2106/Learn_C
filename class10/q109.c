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
    int plus = -1;    // pos to start printing
    int minus = 10;   // how many lines from end

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '+') { //begins from +:extract number
            plus = atoi(argv[i] + 1);
            if (plus < 1) {
                printf("illegal argument\n");
                return 0;                                //difference from q8, prints from +n onward, if n+ is given, -n is ignored.
            }
        } else if (argv[i][0] == '-') {
            minus = atoi(argv[i] + 1);
            if (minus < 0) {
                printf("illegal argument\n");
                return 0;
            }
        } else {
            printf("illegal argument\n");
            return 0;
        }
    }

    char line[LINEMAX];

    // +n mode has priority
    if (plus != -1) {
        int count = 1;
        while (getchars(line, sizeof(line)) >= 0) {
            if (count >= plus)
                printf("%s\n", line);
            count++;
        }
        return 0;
    }

    // -n mode (last n lines)
    char **lines = malloc(sizeof(*lines) * minus);
    int index = 0;

    while (getchars(line, sizeof(line)) >= 0) {
        if (index >= minus)
            free(lines[index % minus]);
        lines[index % minus] = strdup(line);
        index++;
    }

    for (int i = index - minus; i < index; i++) {
        if (i >= 0) {
            printf("%s\n", lines[i % minus]);
            free(lines[i % minus]);
        }
    }

    free(lines);
    return 0;
}
