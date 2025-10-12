#include "main.h"
#include "globals.hpp"
#include "macro/color.hpp"
#include "macro/subsystem.hpp"
#include "helpers.hpp"



void rightSide() {
    chassis.setPose(50, 10, 20);
    intake();
    
    chassis.moveToPoint(58, 30, 1000, {.maxSpeed = 60, .minSpeed = 40, .earlyExitRange = 3});
    chassis.waitUntilDone();
    loader.extend();
    chassis.moveToPoint(65, 37, 1000, {.maxSpeed = 30});
    pros::delay(300);
    chassis.turnToHeading(135, 800, {.maxSpeed = 127});
    chassis.waitUntilDone();
    chassis.setPose(68, 37, 135);

    pros::delay(500);

    chassis.moveToPoint(92, 20, 1000, {.maxSpeed = 60});
    chassis.turnToHeading(168, 1000);
    chassis.waitUntilDone();
    chassis.setPose(92, 20, 180);
    chassis.moveToPose(92, -16, 180, 2000, {.maxSpeed = 80, .minSpeed = 50});

    pros::delay(900);
    chassis.setPose(92, 0, 180);
    chassis.moveToPose(92, 10, 180, 1500, {.forwards = false, .maxSpeed = 70, .minSpeed = 60});
    chassis.waitUntilDone();
    loader.retract();
    chassis.turnToHeading(12, 1000);
    chassis.waitUntilDone();
    
    pros::delay(300);

    chassis.setPose(92, 20, 0);
    chassis.moveToPose(92, 38, 0, 1000, {.maxSpeed = 60, .minSpeed = 50});
    longGoal();
    pros::delay(5500);

    chassis.setPose(92, 36, 0);
    chassis.moveToPose(92, 24, 0, 1000, {.forwards = false, .maxSpeed = 80, .minSpeed = 50});
    chassis.moveToPose(92, 44, 0, 1000, {.maxSpeed = 127, .minSpeed = 100});
}

void rightSideLo() {
    chassis.setPose(50, 10, 20);
    intake();
    
    chassis.moveToPoint(58, 30, 1000, {.maxSpeed = 60, .minSpeed = 40, .earlyExitRange = 3});
    chassis.waitUntilDone();
    loader.extend();
    chassis.moveToPoint(65, 37, 1000, {.maxSpeed = 30});
    pros::delay(300);
    chassis.turnToHeading(135, 800, {.maxSpeed = 127});
    chassis.waitUntilDone();
    chassis.setPose(68, 37, 135);

    pros::delay(300);

    chassis.moveToPoint(91, 20, 1000, {.maxSpeed = 80, .minSpeed = 40});
    chassis.turnToHeading(168, 1000);
    chassis.waitUntilDone();
    chassis.setPose(91, 20, 180);
    chassis.moveToPose(91, -16, 180, 2000, {.maxSpeed = 70, .minSpeed = 50});

    pros::delay(700);
    chassis.setPose(91, 0, 180);
    chassis.moveToPose(91, 15, 180, 1500, {.forwards = false, .maxSpeed = 80, .minSpeed = 60, .earlyExitRange = 3});
    chassis.waitUntilDone();
    loader.retract();
    chassis.turnToHeading(20, 1000);
    chassis.waitUntilDone();
    
    pros::delay(300);

    chassis.setPose(91, 20, 0);
    chassis.moveToPose(91, 38, 0, 1000, {.maxSpeed = 60, .minSpeed = 50});
    longGoal();
    pros::delay(5500);

    chassis.setPose(91, 36, 0);
    chassis.moveToPose(91, 28, 0, 1000, {.forwards = false, .maxSpeed = 80, .minSpeed = 50, .earlyExitRange = 2});
    chassis.moveToPose(91, 44, 0, 1000, {.maxSpeed = 127, .minSpeed = 100});
}

void leftSide() {
    chassis.setPose(-50, 10, -20);
    intake();
    
    chassis.moveToPoint(-58, 30, 1000, {.maxSpeed = 60, .minSpeed = 40, .earlyExitRange = 3});
    chassis.waitUntilDone();
    loader.extend();
    chassis.moveToPoint(-65, 37, 1000, {.maxSpeed = 30});
    pros::delay(300);
    chassis.turnToHeading(-135, 800, {.maxSpeed = 127});
    chassis.waitUntilDone();
    chassis.setPose(-68, 37, -135);

    pros::delay(300);

    chassis.moveToPoint(-92, 20, 1000, {.maxSpeed = 80, .minSpeed = 40});
    chassis.turnToHeading(-167, 1000);
    chassis.waitUntilDone();
    chassis.setPose(-92, 20, -180);
    chassis.moveToPose(-92, -16, -180, 2000, {.maxSpeed = 100, .minSpeed = 80});

    pros::delay(900);
    chassis.setPose(-92, 0, 180);
    chassis.moveToPose(-92, 15, 180, 1500, {.forwards = false, .maxSpeed = 80, .minSpeed = 60, .earlyExitRange = 3});
    chassis.turnToHeading(-12, 1000);
    chassis.waitUntilDone();
    
    pros::delay(500);
    loader.retract();
    chassis.setPose(-92, 20, 0);
    chassis.moveToPose(-92, 33, 0, 1000, {.maxSpeed = 80, .minSpeed = 50});
    chassis.waitUntilDone();
    longGoal();
    pros::delay(5000);
    chassis.moveToPose(-92, 28, 0, 1000, {.forwards = false, .maxSpeed = 80, .minSpeed = 50, .earlyExitRange = 2});
    chassis.moveToPose(-92, 33, 0, 1000, {.maxSpeed = 100, .minSpeed = 80});
}

void soloAWP() {
    chassis.setPose(0, 10, 90);
    intake();

    chassis.moveToPoint(36, 10, 1000, {.maxSpeed = 80, .minSpeed = 40});
    chassis.turnToHeading(180, 1000);
    loader.extend();

}

void skill() {
    
}