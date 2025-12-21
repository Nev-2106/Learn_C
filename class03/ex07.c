#include <stdio.h>

int trim(char *s, int len) {
    while (len > 0 && (s[len-1] == ' ' || s[len-1] == '\t' || s[len-1] == '\n')) {
        s[--len] = '\0';
    }

    int start = 0;
    while (start < len && (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')) {
        start++;
    }

    if (start > 0) {
        int i;
        for (i = 0; i < len - start; ++i) {
            s[i] = s[start + i];
        }
        s[i] = '\0';
        len -= start;
    } else {
        s[len] = '\0';
    }

    return len;
}

int main(void) {
    #define charc 1024
    char line[charc];
    int indx = 0;
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            int n = trim(line, indx);
            if (n > 0) {
                printf("%d %s\n", n, line);
            }
            indx = 0; 
        }
    }

    return 0;
}
