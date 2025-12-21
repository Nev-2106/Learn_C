#include <stdio.h>
#include <ctype.h>

double number;

int getnum(void)
{
    int c;
    double value = 0;


    while (isdigit(c = getchar()))  //getchar reads 1 character at a time using input
        value = value * 10 + (c - '0');//eg if 123 is typed, becomes 1-12-123

    if (c == EOF)
        return -1;

    number = value;//result stored in global variabel "number"
    return 1; // success
}

int main()
{
    while (getnum() != -1)
        printf("%g\n", number);
    return 0;
}

