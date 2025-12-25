#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK 100

int stack[MAX_STACK];
int top = -1;
int variables[26] = {0}; // Array to store values for a-z

void push(int val) {
    if (top < MAX_STACK - 1) stack[++top] = val;
    else { fprintf(stderr, "Stack Overflow\n"); }
}

int pop() {
    if (top >= 0) return stack[top--];
    else { fprintf(stderr, "Stack Underflow\n");}
}

int main() {
    char ch;
    int val;
    int last_var = -1;
    int assignment_pending = 0; // The "Flag"

    printf("RPN Calc:\n");

    while (scanf(" %c", &ch) == 1) {
        if (isdigit(ch)) {
            ungetc(ch, stdin);
            if (scanf("%d", &val) == 1) push(val);
        } 
        else if (isalpha(ch)) {
            int var_idx = tolower(ch) - 'a';
            if (top == -1 && !assignment_pending) {
                // If the stack is empty, this MIGHT be the variable we are assigning to
                last_var = var_idx; 
            }
            push(variables[var_idx]);    
        }
        else if (ch == '=') {
            assignment_pending = 1; // Only assign if '=' is found
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int op2 = pop();
            int op1 = pop();
            switch (ch) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': if(op2 != 0) push(op1 / op2); break;
            }
        }

        // Process end of line
        if (getchar() == '\n') {
            if (top >= 0) {
                int result = stack[top]; 
                // Only save to variables[last_var] if '=' was typed
                if (assignment_pending && last_var != -1) {
                    variables[last_var] = result;
                }
                printf("=> %d\n", pop());
            }
            // Reset flags for the next line
            assignment_pending = 0;
            last_var = -1;
            top = -1; 
        }
    }
    return 0;
}