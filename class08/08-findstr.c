#include <stdio.h>

#define LINEMAX 1000

int getchars(char line[], int limit)
{
    int n = 0, c;
    while (n < limit - 1 && EOF != (c = getchar()) && '\n' != c)
	line[n++] = c;
    if (EOF == c && n == 0) return -1;
    line[n] = '\0';
    return n;
}

int strindex(char string[], char target[])
{
    for (int spos = 0;  string[spos];  ++spos) {
	for (int tpos = 0;  ;  ++tpos) {
	    if (target[tpos] == '\0')              // end of target: success!
		return spos;
	    if (string[spos+tpos] != target[tpos]) // target not at string+spos
		break;
	}
    }
    return -1;
}

int main()
{
    char line[LINEMAX];

    while (getchars(line, LINEMAX) >= 0)
	if (strindex(line, "LINEMAX") >= 0)
	    printf("%s\n", line);

    return 0;
}
