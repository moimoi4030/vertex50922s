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
    while (true) {
        blueSort();
    }
    chassis.setPose(-50, 10, -20);
    chassis.moveToPoint(-58, 30, 1000, {.maxSpeed = 127, .earlyExitRange = 3});

    loader.extend();
    IntakeIntoHoard();

    chassis.moveToPoint(-73, 51, 1000, {.maxSpeed = 70});
    chassis.waitUntil(4);
    loader.retract();
    chassis.waitUntilDone();
    loader.extend();
    pros::delay(500);

    chassis.moveToPoint(-58, 30, 1000, {.forwards = false, .maxSpeed = 127, .earlyExitRange = 3});
    
    

    

    /*loader.extend();
    IntakeIntoHoard();
    chassis.moveToPoint(-8, 35, 1000, {.maxSpeed = 50});
    chassis.waitUntilDone();*/
}

void skill() {
    chassis.setPose(0, 0, 0);
    chassis.moveToPose(0, 43, 0, 1000);
    chassis.waitUntilDone();
    loader.extend();
    chassis.moveToPose(0, 43, 90, 1000);
    chassis.waitUntilDone();
    chassis.cancelAllMotions();
    pros::delay(300);

    IntakeIntoHoard();
    chassis.moveToPose(16, 43, 90, 1000);
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