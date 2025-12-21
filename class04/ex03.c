#include <stdio.h>

void printDigit(int d)
{
    if (d < 10)
        putchar('0' + d);        
    else
        putchar('A' + (d - 10)); 
}

void printHex(int n)
{
    if (n >= 16)
        printHex(n / 16);        
        printDigit(n % 16);          
}

int main()
{
    int n;
    for (n = 0; n <= 20; ++n) {
        printHex(n);
        printf("\n");
    }
    return 0;
}
