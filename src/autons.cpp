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
    chassis.setPose(-60, -25, 90);
    chassis.moveToPose(-36, 0, 0, 2000, {.minSpeed = 72, .earlyExitRange = 2});
    chassis.moveToPose(-60, 23, -90, 2000, {.minSpeed = 72, .earlyExitRange = 2});
}