#include "main.h"
#include "globals.hpp"
#include "macro/color.hpp"
#include "macro/subsystem.hpp"
#include "helpers.hpp"
#include "pros/rtos.hpp"


void redSide() {
    while (true) {
        redSort();
    }
}

void blueSide() {
    chassis.setPose(0, 0, 0);
    chassis.turnToHeading(90, 500);
    chassis.moveToPoint(5, 0, 1000);
    chassis.waitUntilDone();
}

void skill() {
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, 43, 800);
    chassis.waitUntilDone();
    loader.extend();
    chassis.cancelAllMotions();

    chassis.turnToHeading(90, 500, {.maxSpeed = 80});
    chassis.waitUntilDone();
    chassis.cancelAllMotions();
    pros::delay(300);

    IntakeIntoHoard();
    chassis.setPose(0, 43, 90);
    chassis.moveToPoint(16, 43, 1200, {.maxSpeed = 80});
    chassis.waitUntilDone();
    pros::delay(2500);

    chassis.setPose(16, 43, 90);
    chassis.moveToPoint(4, 43, 500, {.forwards = false, .maxSpeed = 70});
    chassis.waitUntilDone();
    chassis.cancelAllMotions();
    pros::delay(700);

    chassis.turnToHeading(-90, 500, {.maxSpeed = 80});
    chassis.waitUntilDone();
    chassis.cancelAllMotions();
    pros::delay(300);

    loader.retract();

    chassis.moveToPoint(-12, 43, 1500);
    chassis.cancelAllMotions();

    Idle();
    longGoal();
    pros::delay(4000);

    chassis.setPose(-12, 43, -90);
    chassis.moveToPoint(-5, 43, 500, {.forwards = false});
    /*
    loader.retract();

    chassis.setPose(2, 30, 270);
    chassis.moveToPoint(-4, 30, 500);
    chassis.waitUntilDone();
    chassis.cancelAllMotions();

    longGoal();
    pros::delay(100000);*/
}