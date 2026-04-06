#ifndef GETOP_H
#define GETOP_H

int getch(void);
void ungetch(int c);
int getop(char line[], int limit);


#endif