#include <stdio.h>

int main()
{
    int d = 0, l = 0, n = 0, t = 0, s = 0, o = 0;

    for (;;) {
        int c = getchar();
        if (c == EOF) break;

        switch (c) {
            case '\n': n++; break;
            case '\t': t++; break;
            case ' ':  s++; break;
            default:
                if (c >= '0' && c <= '9') d++;
                else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) l++;
                else o++;
                break;
        }
    }

    printf("digits:   %3d\n", d);
    printf("letters:  %3d\n", l);
    printf("tabs:     %3d\n", t);
    printf("newlines: %3d\n", n);
    printf("spaces:   %3d\n", s);
    printf("others:   %3d\n", o);

    return 0;
}
