#include "display.h"

void Display::clear() {
    for (int i = 0; i < 64 * 32; i++)
        screen[i] = false;
}

void Display::drawPixel(int x, int y) {
    x = x % 64;
    y = y % 32;

    screen[x + (y * 64)] ^= true;
}