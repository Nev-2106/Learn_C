#include <stdio.h>

int main()
{
    int c;
    int freq[127];
    for (int i = 0; i < 127; i++) freq[i] = 0;

    while ((c = getchar()) != EOF) {
        if (0 <= c && c <= 126)
            freq[c]++;
    }
    for (int i = 0; i < 127; i++) {
        if (freq[i] > 0) {
            if (i == '\t')
                printf("\\t %d\n", freq[i]);
            else if (i == '\n')
                printf("\\n %d\n", freq[i]);
            else if (i == ' ')
                printf("space %d\n", freq[i]);
            else if (i < ' ')
                printf("\\%03o %d\n", i, freq[i]);
            else
                printf("%c %d\n", i, freq[i]);
        }
    }
    return 0;
}