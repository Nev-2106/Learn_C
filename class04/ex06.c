#include <stdio.h>

int digitValue(int c)
{
    if (c >= '0' && c <= '9')
        return c - '0';   
    else
        return -1;        
}

int main()
{
    int c;
    for (c = '/'; c <= ':'; ++c) {
        printf("'%c'->%d\n", c, digitValue(c));
    }
    return 0;
}
