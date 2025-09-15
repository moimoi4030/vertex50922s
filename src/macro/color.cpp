#include "main.h"
#include "color.hpp"
#include "globals.hpp"

// color sort
const int NONE = 0;
const int RED = 1;
const int BLUE = 2;

int detectColor() {
    int hue = optical.get_hue();
    if(optical.get_proximity() < 150) {
        return NONE;
    }
    if(hue > 0 && hue < 10) {
        return RED;
    }
    if(hue > 220 && hue < 270) {
        return BLUE;
    }
    return NONE;
}

void colorSort(int color) {
    if(detectColor() == color) {
        sup3.move(-127);
        pros::delay(200);

        intake();
    }
}

void redSort() {
    colorSort(RED);
}

void blueSort() {
    colorSort(BLUE);
}

void offSort() {
    colorSort(NONE);
}