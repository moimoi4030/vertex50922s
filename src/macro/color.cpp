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
        stage3.move(-127);
        pros::delay(400);

        intake();
    } 
}

void redSort() { 
    colorSort(RED);
    master.clear_line(0);
    master.set_text(0, 0, "BLUE");
}

void blueSort() { 
    colorSort(BLUE);
    master.clear_line(0);
    master.set_text(0, 0, "RED");
}

void offSort() {
    colorSort(NONE);
    master.clear_line(0);
    master.set_text(0, 0, "OFF");
}

int currentMode = BLUE;

void switchSort() {
    if (currentMode == NONE) currentMode = BLUE;
    else if (currentMode == BLUE) currentMode = RED;
    else if (currentMode == RED) currentMode = NONE;
    
    switch (currentMode) {
        case BLUE:
            blueSort();
            break;
        case RED:
            redSort();
            break;
        case NONE:
            offSort();
            break;
    }
}