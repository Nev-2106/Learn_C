#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "calculator.h"
/* getop - read and return operator, or read a number into a buffer */
int main()
{
	char line[32];
	for (;;) {
	int c = getop(line, sizeof(line));
	if (c < 0) break;
	switch (c) {
	  case 0:  	while (depth) printf("=> %g\n", pop());				break;
	  case NUMBER:	push(atod(line));						break;
	  case '+':	{ double r = pop(), l = pop();  push(l + r); }			break;
	  case '-':	{ double r = pop(), l = pop();  push(l - r); }			break;
	  case '*':	{ double r = pop(), l = pop();  push(l * r); }			break;
	  case '/':	{ double r = pop(), l = pop();  push(l / r); }			break;
	  case '%':	{ double r = pop(), l = pop();  push(l - r*(int)(l/r)); }	break;
	  default:	printf("unknown operator: %c\n", c);				break;
	}
	}

	return 0;
}
