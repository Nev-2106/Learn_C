#include <stdio.h>

#define MAXLINE 100

void reverse(char s[], int len) {
    int i, j;
    char tmp;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

int main(void) {
    char line[MAXLINE];
    int c;

    while (1) {
        int len = 0;
        int has_newline = 0;
        while ((c = getchar()) != EOF && c != '\n') {
            if (len < MAXLINE - 1) {
                line[len++] = (char)c;
            }
        }

        if (c == '\n') has_newline = 1;
        if (c == EOF && len == 0) break;
        line[len] = '\0'; reverse(line, len);
        if (has_newline)printf("%s\n", line);
        else printf("%s", line);
        if (c == EOF)
            return 0;
    }

    return 0;
}