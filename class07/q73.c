#include <stdio.h>

double stack[32];
int depth = 0; //keeps track of how many items currently in stack

void push(double d)      //stores d at steck[depth] 
{
    if (depth < 32)
        stack[depth++] = d;   //stores, then increments it
    else
        printf("stack overflow\n");
}

double pop(void)  //pop decrements depth
{
    if (depth > 0)
        return stack[--depth];
    else {
        printf("stack underflow\n");
        return 0;
    }
}

int main()
{
    push(1.0);
    push(2.0);
    push(3.0);
    printf("%g\n", pop());
    printf("%g\n", pop());
    push(4.0);
    push(5.0);
    printf("%g\n", pop());
    printf("%g\n", pop());
    printf("%g\n", pop());
    return 0;
}
