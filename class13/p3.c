#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

double pop(void);
void push(double d);
double atod(char line[]);
int depth = 0;

int main()
{
    char op[32];
    
    for (;;) {
        if (scanf("%31s", op) != 1) {
            while (depth) printf("=> %g\n", pop());
            break;
        }
        
        if (strcmp(op, "q") == 0) {
            while (depth) printf("=> %g\n", pop());
            break;
        }
        else if (isdigit(op[0]) || op[0] == '.' || op[0] == '-') {
            push(atod(op));
        }
        else {
            char c = op[0];
            switch (c) {
                case '+': { double r = pop(), l = pop(); push(l + r); } break;
                case '-': { double r = pop(), l = pop(); push(l - r); } break;
                case '*': { double r = pop(), l = pop(); push(l * r); } break;
                case '/': { double r = pop(), l = pop(); push(l / r); } break;
                case '%': { double r = pop(), l = pop(); push(l - r*(int)(l/r)); } break;
                default: printf("unknown operator: %c\n", c); break;
            }
        }
    }
    return 0;
}


double stack[32];

int stackDepth(void) {
    return depth;
}

void push(double d) {
    if (depth >= 32)
        printf("stack overflow\n");
    else
        stack[depth++] = d;
}

double pop(void) {
    if (depth < 1) {
        printf("stack underflow\n");
        return 0;
    }
    return stack[--depth];
}

double atod(char line[]) {
    int i = 0;
    int sign = 1;
    while (isspace(line[i])) ++i;
    if (line[i] == '-') {
        sign = -1;
        ++i;
    }
    double value = 0.0;
    while (isdigit(line[i])) value = value * 10.0 + line[i++] - '0';
    if (line[i] == '.') {
        i++;
        double scale = 1.0;
        while (isdigit(line[i])) {
            value = value * 10.0 + line[i++] - '0';
            scale *= 10.0;
        }
        value /= scale;
    }
    return sign * value;
}