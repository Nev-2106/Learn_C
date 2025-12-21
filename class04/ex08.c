#include <stdio.h>

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

    if (value < b)
        return value;
    else
        return -1;
}

int strtoi(const char *s, int b)
{
    int value = 0;
    int d;

    while (*s != '\0') {         
        d = digitValue(*s, b);    
        if (d == -1)              
            break;
        value = value * b + d;    
        s++;
    }

    return value;
}

// Test program
int main()
{
    printf("strtoi(\"1010\",  2) = %d\n", strtoi("1010", 2));
    printf("strtoi(\"1010\",  8) = %d\n", strtoi("1010", 8));
    printf("strtoi(\"1010\", 10) = %d\n", strtoi("1010", 10));
    printf("strtoi(\"1010\", 16) = %d\n", strtoi("1010", 16));
    printf("strtoi(\"2A\",   16) = %d\n", strtoi("2A", 16));

    printf("\nTesting invalid digits:\n");
    printf("strtoi(\"1012\",  2) = %d\n", strtoi("1012", 2));
    printf("strtoi(\"1789\",  8) = %d\n", strtoi("1789", 8));
    printf("strtoi(\"101A\", 10) = %d\n", strtoi("101A", 10));
    printf("strtoi(\"2FGH\", 16) = %d\n", strtoi("2FGH", 16));

    return 0;
}
