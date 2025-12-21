#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "calculator.h"
double atod(char line[])
{
	int i = 0;
	while (isspace(line[i])) ++i;
	double value = 0.0;
	while (isdigit(line[i])) value = value * 10.0 + line[i++] - '0';
	if ('.' == line[i++]) {
	double scale = 1.0;
	while (isdigit(line[i])) {
		value = value * 10.0 + line[i++] - '0';
		scale *= 10.0;
	}
	value /= scale;
	}
	return value;
}
