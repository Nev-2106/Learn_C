#include<stdio.h>
void printNumber(int i)
{
    if (i >= 2) printNumber(i / 2);
    putchar('0' + i % 2);
}


int main()
{
    int i;
    for(i=0; i<=20; ++i){
        printNumber(i);
        printf("\n");
    }
    return 0;
}