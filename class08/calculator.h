#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUMBER '0' // `operator' representing a number

int getch(void); /* prototype for getch (real definition later) */

/* forward declarations for functions used by main */
int getop(char line[], int limit);
int stackDepth(void);
double pop(void);
void push(double d);
double atod(char line[]);
int depth = 0;

int saved = 0;
