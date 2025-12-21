#include <stdio.h>

#define LINEMAX 50   // later reduce to 50 to test
int copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
    return i;
}

int getchars(char line[], int max) {
    int c, i = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        if (i < max - 1)
            line[i] = c;
        i++;
    }
    if (c == '\n') {
        if (i < max - 1)
            line[i] = c;
        i++;
    }
    if (i < max)
        line[i] = '\0';
    else
        line[max - 1] = '\0';

    return i;
}

int main(void) {
    char line[LINEMAX];
    char longest[LINEMAX];
    int len, max = 0, total_len;

    while ((total_len = getchars(line, LINEMAX)) > 0) {
        if (total_len > max) {
            max = total_len;
            copy(longest, line);
        }
    }

    printf("%s\n", longest);
    return 0;
}



