#include <stdio.h>
#include <ctype.h>  

int digitValue(int c, int b)
{
    int value;

    if (c >= '0' && c <= '9')
        value = c - '0';
    else if (c >= 'A' && c <= 'Z')
        value = c - 'A' + 10;
    else if (c >= 'a' && c <= 'z')
        value = c - 'a' + 10;
    else
        return -1;

    return (value < b) ? value : -1;
}

int strtoi(const char *s, int b)
{
    int value = 0;
    int d;
    int sign = 1;   

   
    while (isspace(*s))
        s++;

    
    while (*s == '+' || *s == '-') {
        if (*s == '-')
            sign = -sign;  
        s++;
    }

    
    while (*s != '\0') {
        d = digitValue(*s, b);
        if (d == -1)
            break;
        value = value * b + d;
        s++;
    }

    
    return sign * value;
}

int main()
{
    printf("%d\n", strtoi("  101010", 2));
    printf("%d\n", strtoi(" +52", 8));
    printf("%d\n", strtoi("++42", 10));
    printf("%d\n", strtoi("  2a", 16));
    printf("%d\n", strtoi(" -2A", 16));
    printf("%d\n", strtoi("--2A", 16));
    printf("%d\n", strtoi("  7fffffff", 16));
    printf("%d\n", strtoi("  ffffffff", 16));
    printf("%d\n", strtoi(" -ffffffff", 16));
    printf("%d\n", strtoi("  80000000", 16));
    printf("%d\n", strtoi(" -80000000", 16));
    return 0;
}
