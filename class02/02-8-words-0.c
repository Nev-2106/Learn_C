#include <stdio.h>
#define OUTSIDE  0  // not in a word
#define INSIDE   1  // in a word
int main()
{
    int c, state, count=0;
    state = OUTSIDE;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUTSIDE;
        }
        else if(state == OUTSIDE) {
                printf("word begins with %c\n", c);
                count++;
                state = INSIDE;
        }
    }
    printf("Number of words %d\n",count);
    return 0;
}
