#ifndef COLOUR_H
#define COLOUR_H

enum Colour {
	BLACK, RED, GREEN, YELLOW, BLUE, PURPLE, CYAN, WHITE
};

int colour_print(enum Colour colour, int bold, const char* __restrict__ __format, ...);

#endif // !COLOUR_H