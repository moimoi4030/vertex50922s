#include "autons.hpp"
#include "main.h"
#include "globals.hpp"
#include "macro/color.hpp"
#include "macro/subsystem.hpp"
#include "helpers.hpp"

#include "localization/ekf.hpp"
#include "motion/ramsete.hpp"
#include "pros/rtos.hpp"
#include <math.h>

// ekf task
void ekfLocalization(void*) {
    EKF ekf(0, 17, 0, 0.01);
    double track_width = 13.0;
    double wheel_radius = 3.25 / 2;

    while (true) {
        double vL = left.get_actual_velocity() * (2 * M_PI * wheel_radius) / 60.0;
        double vR = right.get_actual_velocity() * (2 * M_PI * wheel_radius) / 60.0;

        double v = (vL + vR) / 2.0;
        double w = (vR - vL) / track_width;

        ekf.predict(v, w);

        ekf.update(chassis.getPose().x, chassis.getPose().y, chassis.getPose().theta);

        State filtered = ekf.getState();

        chassis.setPose(filtered.x, filtered.y, filtered.theta);

        pros::delay(10);
    }
}



// test   
void Test() {
    chassis.setPose(0, 17, 0);
    intake();
    chassis.moveToPoint(0, 30, 1500, {.minSpeed = 40, .earlyExitRange = 3});
    chassis.moveToPose(10, 42, 27, 2000, {.maxSpeed = 70});

    chassis.turnToHeading(130, 1000);

    chassis.moveToPoint(32, 22, 2000, {.maxSpeed = 70, .minSpeed = 30, .earlyExitRange = 6});
    chassis.moveToPose(32, 4, 180, 2800, {.maxSpeed = 70});
    chassis.waitUntil(2);
    loader.extend();

    chassis.moveToPoint(32, 16, 2000, {.forwards = false});
    chassis.turnToPoint(30.3, 27.5, 1500);
    loader.retract();
    Idle();
    chassis.moveToPoint(30.3, 27.5, 1500);

    chassis.waitUntilDone();
    preLongGoal();
    pros::delay(500);
    longGoal();

    pros::delay(3600);
    chassis.moveToPoint(32, 18, 2000, {.forwards = false});

    chassis.moveToPose(4, 40, -5, 5000);
}

// autonomous routines
void Long7Rush() {
    chassis.setPose(0, 17, 0);
    intake();

    chassis.moveToPose(10, 42, 27, 1400);
    chassis.waitUntil(15);
    loader.extend();

    chassis.turnToHeading(130, 800);

    chassis.moveToPoint(31.5, 14, 2000, {.minSpeed = 50, .earlyExitRange = 3});
    chassis.moveToPose(31.5, -3, 180, 1200, {.maxSpeed = 70});


    chassis.moveToPoint(31.5, 12, 2000, {.forwards = false});
    chassis.turnToPoint(30, 30, 1000);
    loader.retract();
    chassis.moveToPoint(30, 30, 1500);

    chassis.waitUntilDone();
    longGoal();

    pros::delay(3000);
    chassis.moveToPoint(30.5, 19, 4000, {.forwards = false});
    descore.extend();
    chassis.moveToPose(15, 60, 0, 1500);
    chassis.waitUntil(26);
    descore.retract();

    chassis.waitUntilDone();
    chassis.turnToHeading(-30, 1000);
}

void Long7Center2() {
    chassis.setPose(0, 17, 0);
    intake();

    chassis.moveToPoint(0, 30, 1500, {.minSpeed = 40, .earlyExitRange = 3});
    chassis.moveToPose(-10, 42, -27, 2000, {.maxSpeed = 70});

    /*chassis.turnToHeading(130, 1000);
    chassis.moveToPoint(32, 20, 2000, {.maxSpeed = 100, .minSpeed = 50, .earlyExitRange = 4});
    chassis.moveToPose(32, 3, 179, 1500, {.maxSpeed = 60});
    chassis.waitUntil(4);
    loader.extend();

    chassis.moveToPoint(31, 20, 2000, {.forwards = false});
    chassis.turnToHeading(0, 1500);
    loader.retract();
    chassis.moveToPoint(31, 30, 1500);

    chassis.waitUntilDone();
    longGoal();

    pros::delay(3000);
    chassis.moveToPoint(31, 22, 2000, {.forwards = false});
    descore.extend();
    chassis.moveToPose(26, 33, -14, 2000, {.minSpeed = 80, .earlyExitRange = 3});
    chassis.moveToPose(17, 54, 0, 1500, {.maxSpeed = 80});
    chassis.waitUntil(12);
    descore.retract();

    chassis.waitUntilDone();
    chassis.turnToHeading(-30, 1000);*/
}

void soloAWP() {
    
}

void skill() {
    
}