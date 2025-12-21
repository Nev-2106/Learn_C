#include <stdio.h>
#include <ctype.h>

#define STACK_SIZE 32


double stack[STACK_SIZE];
int depth = 0;     //keeps track of how many numbers are in the stack

void push(double d)
{
    if (depth < STACK_SIZE)
        stack[depth++] = d;//adds a number to the top of the stack
    else
        printf("Error: stack overflow\n");
}
// push pop handle saving and retrieving numbers using the LIFO principle.
double pop(void)
{
    if (depth > 0)
        return stack[--depth];
    else {
        printf("Error: stack underflow\n");
        return 0.0;
    }
}


double number;  // global variable to hold numeric value

int getop(void)
{
    int c;

    // skip spaces/tabs; newline ends the expression
    do {
        c = getchar();
        if (c == EOF) return -1;
        if (c == '\n') return 0;//skips spaces
    } while (isblank((unsigned char)c));

    // if it’s not a digit, '.', '+', or '-', return as operator
    if (!isdigit(c) && c != '.' && c != '+' && c != '-') {
        return c;
    }

    // handle optional unary sign
    int sign = 1;
    if (c == '+' || c == '-') {
        int next = getchar();
        if (isdigit(next) || next == '.') {
            sign = (c == '-') ? -1 : 1;
            c = next; // continue parsing number
        } else {
            // it’s a binary operator
            if (next != EOF) ungetc(next, stdin);
            return c; // return '+' or '-' as operator
        }
    }
//before the decimal point, it builds the decimal part: 12 - 1*10 + 2 = 12
    // parse number
    double val = 0.0, scale = 1.0;  //after the decimal point, it divides each next digit by powers of 10
    while (isdigit(c)) {
        val = val * 10.0 + (c - '0');
        c = getchar();  //for 0.25, after . digit 2 - val+=2/10=0.2
    } //next digit 5, val+=5/100=0.05. After that total = 0.05
    if (c == '.') {
        c = getchar();
        while (isdigit(c)) {
            val = val * 10.0 + (c - '0');
            scale *= 10.0;
            c = getchar();
        }
    }

    number = sign * (val / scale);

    if (c != EOF) ungetc(c, stdin);

    return '0'; // number
}

// has context menu
// ===== main() calculator =====
int main(void)
{
    int c;
    while ((c = getop()) != -1) {
        switch (c) {
            case '0':  // number
                push(number);
                break;

            case '+': {
                double b = pop();
                double a = pop();
                push(a + b);
                break;
            }

            case '-': {
                double b = pop();
                double a = pop();
                push(a - b);
                break;
            }

            case '*': {
                double b = pop();
                double a = pop();
                push(a * b);
                break;
            }

            case '/': {
                double b = pop();
                if (b != 0.0) {
                    double a = pop();
                    push(a / b);
                } else {
                    printf("Error: divide by zero\n");
                }
                break;
            }

            case 0: // newline
                if (depth > 0)
                    printf("%g\n", pop());
                break;

            default:
                printf("unknown operator '%c'\n", c);
                break;
        }
    }
    return 0;
}
