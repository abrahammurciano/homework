#include "colour.h"
#include <stdio.h>
#include <stdarg.h>

void setcolour(enum Colour colour, int bold) {
	printf("\033[%d;3%dm", bold, colour);
}

void resetcolour() {
	printf("\033[0m");
}

int colour_print(enum Colour colour, int bold, const char* __restrict__ __format, ...) {
	va_list args;
	va_start(args, __format);
	setcolour(colour, bold);
	int result = printf(__format, args);
	resetcolour();
	va_end(args);
	return result;
}