#include "main.h"
#include "color.hpp"
#include "globals.hpp"

// color sort
const int NONE = 0;
const int RED = 1;
const int BLUE = 2;

int detectColor() {
    int hue = optical.get_hue();
    if(optical.get_proximity() < 100) {
        return NONE;
    }
    if(hue > 350 && hue < 20) {
        return RED;
    }
    if(hue > 220 && hue < 270) {
        return BLUE;
    }
    return NONE;
}

void colorSort(int color) {
    if(detectColor() == color) {
        sortAlign.extend();
        pros::delay(600);

        sortAlign.retract();
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