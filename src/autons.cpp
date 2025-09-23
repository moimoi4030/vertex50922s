#include "main.h"
#include "globals.hpp"
#include "macro/color.hpp"
#include "macro/subsystem.hpp"
#include "helpers.hpp"


void redSide() {
    while (true) {
        redSort();
    }
}

void blueSide() {
    while (true) {
        blueSort();
    }
}

void skill() {
    chassis.setPose(0, 0, 180);
    chassis.moveToPoint(0, 10, 10000);
}