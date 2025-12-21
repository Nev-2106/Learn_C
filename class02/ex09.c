#include <stdio.h>
#define OUTSIDE  0  // not in a word
#define INSIDE   1  // in a word
int main()
{
    int c, state, count=0, charcount=0,lcount=0;
    state = OUTSIDE;
    while ((c = getchar()) != EOF) {
        charcount++;
        if(c == '\n') lcount++;
        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUTSIDE;
        }
        else if(state == OUTSIDE) {
                printf("word begins with %c\n", c);
                count++;
                state = INSIDE;
        }
    }
    printf("Number of Words:  %d\n",count);
    printf("Number of Charcters:  %d\n",charcount);
    printf("Number of Lines: %d\n",lcount);

    return 0;
}
