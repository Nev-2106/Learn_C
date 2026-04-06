#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



#include "atod.h"
#include "stack.h"
#include "getop.h"
#include "calculator.h"

//function prototypes 
int getch(void);
void ungetch(int c);
int getop(char line[], int limit);
int stackDepth(void);
void push(double d);
double pop(void);
double atod(char line[]);
int main();


/* main - the main calculator program */

int main()
{
    char line[32];
    for (;;) {
	int c = getop(line, sizeof(line));
	if (c < 0) break;
	switch (c) {
						//changed to stack depth
	  case 0:  	while (stackDepth()) printf("=> %g\n", pop());					break;
	  case NUMBER:	push(atod(line));									break;
	  case '+':	{ double r = pop(), l = pop();  push(l + r); }			break;
	  case '-':	{ double r = pop(), l = pop();  push(l - r); }			break;
	  case '*':	{ double r = pop(), l = pop();  push(l * r); }			break;
	  case '/':	{ double r = pop(), l = pop();  push(l / r); }			break;
	  case '%':	{ double r = pop(), l = pop();  push(l - r*(int)(l/r)); }	break;
	  default:	printf("unknown operator: %c\n", c);					break;
	}
    }

	//printf("%i\n", depth); //THIS WAS CHANGED 
    return 0;
}
