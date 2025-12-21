#include <stdio.h>
#include <ctype.h>

double stack[32];
int depth = 0;
double number;

void push(double d) { stack[depth++] = d; }
double pop(void) { return stack[--depth]; }

int getop(void) {
    int c;
    while (isblank(c = getchar()))
        ;
    if (c == EOF) return -1;
    if (c == '\n') return 0;
    if (!isdigit(c)) return c;
//when getop returns +, pop rhs, pop lhs, then compute lhs+rhs
    double val = 0;
    do {
        val = val * 10 + (c - '0');
        c = getchar();
    } while (isdigit(c));

    number = val;
    return '0';            //when getop returns 0, push number into stack
}

int main(void) {
    for (;;) {
        int c = getop();
        switch (c) {
            case -1: return 0;
            case 0:
                while (depth > 0)
                    printf("%g\n", pop());
                break;
            case '0':
                push(number);
                break;
            case '+': {
                double rhs = pop(), lhs = pop();
                push(lhs + rhs);
                break;
            }
            default:
                printf("unknown '%c'\n", c);
        }
    }
}
