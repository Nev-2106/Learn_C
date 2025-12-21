#include <stdio.h>
#include <ctype.h>

double stack[32];
int depth = 0; //tracks how many items are in the stack
double number;  //holds last number read by getop()
int buf = EOF;  // single-character pushback buffer

// --- Input buffer functions ---
int getch(void) {  //reads 1 character. if there's something saved in buf, it returns that. otherwise reads next chaacter from keyboard
    if (buf != EOF) {
        int c = buf;
        buf = EOF;
        return c;
    }
    return getchar();
}

void ungetch(int c) {  //pushes back one character 
    buf = c;
}

// --- Stack functions ---
void push(double d) {
    if (depth < 32)
        stack[depth++] = d;
    else
        printf("stack overflow\n");
}

double pop(void) {
    if (depth > 0)
        return stack[--depth];
    printf("stack underflow\n");
    return 0;
}

// --- Improved getop() with negative numbers and decimals ---
int getop(void) {
    int c;
    while (isblank(c = getch()))   // skip blanks
        ;

    if (c == EOF) return -1;
    if (c == '\n') return 0;

    int sign = 1;  // positive by default

    // detect negative number
    if (c == '-') {
        int next = getch();
        if (isdigit(next) || next == '.') {
            sign = -1;   // negative number confirmed
            c = next;    // continue reading the number
        } else {
            ungetch(next);  // not a number, so it's subtraction operator
            return '-';
        }
    }

    if (!isdigit(c) && c != '.')
        return c;  // operator

    double val = 0.0;
    int seen_dot = 0;
    double frac_div = 1.0;

    // read integer and fractional parts
    do {
        if (c == '.') {
            seen_dot = 1;
        } else if (!seen_dot) {
            val = val * 10 + (c - '0');
        } else {
            frac_div *= 10.0;
            val += (c - '0') / frac_div;
        }
        c = getch();
    } while (isdigit(c) || (!seen_dot && c == '.'));

    ungetch(c);  // push back extra char
    number = val * sign;
    return '0';
}

// --- Main calculator loop ---
int main(void) {
    for (;;) {
        int c = getop();
        switch (c) {
            case -1: return 0;
            case 0:
                while (depth > 0)
                    printf("%g\n", pop());
                break;
            case '0': push(number); break;
            case '+': push(pop() + pop()); break;
            case '-': {
                double rhs = pop(), lhs = pop();
                push(lhs - rhs);
                break;
            }
            case '*': push(pop() * pop()); break;
            case '/': {
                double rhs = pop(), lhs = pop();
                if (rhs != 0)
                    push(lhs / rhs);
                else
                    printf("division by zero\n");
                break;
            }
            case '%': {
                double rhs = pop(), lhs = pop();
                if (rhs != 0)
                    push(lhs - rhs * (int)(lhs / rhs));
                else
                    printf("mod by zero\n");
                break;
            }
            default:
                printf("unknown '%c'\n", c);
        }
    }
}
