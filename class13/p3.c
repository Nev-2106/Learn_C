#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK 100

int stack[MAX_STACK];
int top = -1;

// Basic stack operations
void push(int val) {
    if (top < MAX_STACK - 1) {
        stack[++top] = val;
    } else {
        fprintf(stderr, "Error: Stack Overflow\n");
        exit(1);
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        fprintf(stderr, "Error: Stack Underflow (check your expression)\n");
        exit(1);
    }
}

int main() {
    char ch;
    int val;

    printf("Enter RPN expression (e.g., 1 2 3*4++): \n");

    // The space before %c tells scanf to skip whitespace
    while (scanf(" %c", &ch) == 1) {
        if (isdigit(ch)) {
            // Put the digit back so scanf("%d") can read the whole number
            ungetc(ch, stdin);
            if (scanf("%d", &val) == 1) {
                push(val);
            }
        } 
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            // Pop operands in reverse order
            int op2 = pop();
            int op1 = pop();
            
            switch (ch) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': 
                    if (op2 == 0) {
                        fprintf(stderr, "Error: Division by zero\n");
                        return 1;
                    }
                    push(op1 / op2); 
                    break;
            }
        } 
        else if (ch == '.') { // Using '.' as a sentinel to print result
            break;
        }
    }

    if (top >= 0) {
        printf("Result: %d\n", pop());
    } else {
        printf("No result found.\n");
    }

    return 0;
}