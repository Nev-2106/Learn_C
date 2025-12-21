#include <stdio.h>

#define LOW 0
#define HIGH 9
#define STEP 1

int main()
{
    int c,num,cnt=0;
    int d[10] = {0,0,0,0,0,0,0,0,0,0};
    while ((c = getchar()) != EOF) {
        if ('0' <= c && c <= '9') {
            ++d[c - '0'];
        }
    }
    printf("Digit Count Histogram\n");
    for(num = LOW;num<= HIGH;num = num+STEP){
        printf("%d %d ",num, d[num]);
        for(int i = 0; i < d[num]; i++) {
            putchar('*');
        }
        printf("\n");
    }
}
