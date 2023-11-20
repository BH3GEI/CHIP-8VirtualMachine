#include "keyboard.h"
#include <iostream>

// Initialize keys to false
Keyboard::Keyboard() {
    for (int i = 0; i < 16; ++i) {
        keys[i] = false;
    }
}

bool Keyboard::isKeyPressed(unsigned char key) {
    if (key < 16) {
        return keys[key];
    }

    return false;
}

unsigned char Keyboard::waitForKeyPress() {

    unsigned char key;
    std::cin >> key;

    return key;
}

void Keyboard::keyDown(unsigned char key) {
    if (key < 16) {
        keys[key] = true;
    }
}

void Keyboard::keyUp(unsigned char key) {
    if (key < 16) {
        keys[key] = false;
    }
}