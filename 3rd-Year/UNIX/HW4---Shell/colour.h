#ifndef COLOUR_H
#define COLOUR_H

enum Colour {
	BLACK, RED, GREEN, YELLOW, BLUE, PURPLE, CYAN, WHITE
};

void setcolour(enum Colour colour, int bold);

void resetcolour();

int colour_print(enum Colour colour, int bold, const char* __restrict__ __format, ...);

#endif // !COLOUR_H