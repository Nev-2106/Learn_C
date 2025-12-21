#include <stdio.h>

#define LINEMAX 100

int main(void) {
    char line[LINEMAX];
    int c;
    int len = 0, pos = 0;

    while ((c = getchar()) != EOF) {
        if (c != '\n') {
            if (pos < LINEMAX - 1) {
                line[pos++] = (char)c;
            }
            len++;
        } else {
            line[pos] = '\0';
            if (len > 80) {
                printf("%zu %s\n", len, line);
            }
            len = pos = 0;
        }
    }

    if (len > 0) {
        line[pos] = '\0';
        if (len > 80) {
            printf("%zu %s\n", len, line);
        }
    }

    return 0;
}
