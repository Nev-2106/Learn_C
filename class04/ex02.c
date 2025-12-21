#include<stdio.h>
void printDigit(int d)
{
    if (d < 10)
        putchar('0' + d);
    else
        putchar('A' + (d - 10));
}


int main()
{
    int n;
    for(n=0; n<=20; ++n){
        printDigit(n);
        printf("\n");
    }
    return 0;
}