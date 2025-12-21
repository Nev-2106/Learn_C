#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdio.h>
#include <ctype.h>

/* --- Constant used by getop() and main() --- */
#define NUMBER '0'   /* signal that a number was found */

/* --- Shared variable from stack.c --- */
extern int depth;

/* --- Function prototypes --- */
int getop(char line[], int limit);
double atod(char line[]);
void push(double d);
double pop(void);
int stackDepth(void);

#endif
