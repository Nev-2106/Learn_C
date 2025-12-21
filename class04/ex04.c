#include <stdio.h>

void printDigit(int d)
{
    if (d < 10)
        putchar('0' + d);        
    else
        putchar('A' + (d - 10)); 
}

void printNumber(int n, int b)
{
    if (n >= b)
        printNumber(n / b, b);   
    printDigit(n % b);           
}

int main()
{
    int base;
    for (base = 2; base <= 20; ++base) {
        printNumber(42, base);
        printf("\n");
    }
    return 0;
}
