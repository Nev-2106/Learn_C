#include <stdio.h>

int main()
{
    int i;

    // do loop
    i = 0;
    do {
        if (i == 3) continue;//continue skips printing and jumps to while (i++ < 5)
        printf("%2d", i);//condition increments i after each iteration
    } while (i++ < 5);
    printf("\n");

    // do loop using labels and goto
    i = 0;
  doBody://marks the start of the loop body
    if (i == 3) goto doTest;//if i=3 we jump directly to the test
    printf("%2d", i);//executed only when i!=3
  doTest:
    if (i++ < 5) goto doBody;//tthe condition i++<5 is checked, nd if true jumps back to doBody.
    printf("\n");

    // while loop
    i = 0;
    while (i++ < 5) {
        if (i == 3) continue;//skips printing and continue to next check.
        printf("%2d", i);
    }
    printf("\n");

    // while loop using labels and goto
    i = 0;
  whileTest://label for condition checking
    if (i++ >= 5) goto whileEnd;//jump to end.
    if (i == 3) goto whileTest;  // acts like 'continue'
    printf("%2d", i);
    goto whileTest;
  whileEnd:
    printf("\n");

    // for loop
    for (i = 0;  i < 5;  ++i) {
        if (i == 3) continue;
        printf("%2d", i);
        if (i == 4) break;
    }
    printf("\n");

    // for loop using labels and goto
    i = 0;
  forTest:
    if (i >= 5) goto forEnd;
    if (i == 3) { i++; goto forTest; }  // acts like 'continue'
    printf("%2d", i);
    if (i == 4) goto forEnd;            // acts like 'break'
    i++;
    goto forTest;
  forEnd:
    printf("\n");

    return 0;
}
