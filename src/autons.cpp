#include "autons.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "main.h"
#include "globals.hpp"
#include "macro/color.hpp"
#include "helpers.hpp"
#include "pros/rtos.hpp"


// test   
void Test() {
    chassis.setPose(15, 24, 0);
    Wing.extend();
    Intake();

    chassis.moveToPoint(24, 47, 1100, {.maxSpeed = 80});
    chassis.waitUntil(12.5);
    Loader.extend();

    chassis.turnToPoint(13.5, 58.5, 700, {});
    Loader.retract();
    chassis.moveToPoint(13.5, 58.5, 1000, {.maxSpeed = 60}, false);
    LowGoal();

    pros::delay(2200);
    Intake();

    chassis.moveToPoint(30, 40, 800, {.forwards = false}, false);
    Loader.extend();
    Intake();
    chassis.moveToPose(46, 9, 180, 4500, {.lead = 0.7, .maxSpeed = 70});

    chassis.moveToPoint(46, 20, 900, {.forwards = false, .maxSpeed = 80, .minSpeed = 70}, false);

    chassis.moveToPoint(56, 40, 1200, {.forwards = false, .maxSpeed = 80, .minSpeed = 70});
    Loader.retract();

    chassis.moveToPose(56, 90, 180, 5000, {.forwards = false, .maxSpeed = 80, .minSpeed = 70});
    chassis.moveToPoint(48, 110, 3000, {.forwards = false, .maxSpeed = 80, .minSpeed = 70});

    chassis.moveToPose(42, 100, 0, 1300, {.forwards = false, .maxSpeed = 70, .minSpeed = 60});
    chassis.moveToPoint(42, 95, 500, {.forwards = false, .maxSpeed = 70}, false);
    LongGoal();

    pros::delay(2500);
    Intake();
    pros::delay(300);

    Loader.extend();

    chassis.moveToPoint(41.5, 131, 3500, {.maxSpeed = 50});

    chassis.moveToPoint(42, 95, 1300, {.forwards = false, .maxSpeed = 70}, false); 
    LongGoal();

    pros::delay(2000);
    Intake();
    pros::delay(300);

    chassis.moveToPoint(42, 110, 1000, {.maxSpeed = 80});

    
    Intake();
    Loader.retract();
    chassis.moveToPoint(17.5, 93, 1500, {.maxSpeed = 80, .minSpeed = 70});
    chassis.waitUntil(17);
    Loader.extend();
    chassis.moveToPoint(15, 50, 2000, {.maxSpeed = 80, .minSpeed = 70}, false);
    Loader.retract();

    chassis.moveToPoint(-25, 48, 1500, {.maxSpeed = 80});
    chassis.waitUntil(32);
    Loader.extend();

    chassis.turnToPoint(-18.7, 57.4, 800, {.forwards = false});
    chassis.moveToPoint(-18.7, 57.4, 1500, {.forwards = false, .maxSpeed = 60}, false);
    MidGoal();

    pros::delay(2700);
    Intake();
    pros::delay(200);

    chassis.moveToPoint(-30, 55, 2000, {.maxSpeed = 80});
    Loader.retract();

    chassis.moveToPose(-30, 92, 0, 3000, {.maxSpeed = 80, .minSpeed = 70});
    chassis.moveToPose(-53, 130, 0, 4500, {.maxSpeed = 80});
    Loader.extend();

    chassis.moveToPoint(-53, 120, 1000, {.forwards = false, .maxSpeed = 80, .minSpeed = 70}, false);

    chassis.moveToPoint(-42, 100, 1200, {.forwards = false, .maxSpeed = 80, .minSpeed = 70});
    Loader.retract();
    
    chassis.moveToPose(-36, 50, 0, 4000, {.forwards = false, .maxSpeed = 80, .minSpeed = 70});
    chassis.moveToPoint(-49, 30, 3000, {.forwards = false, .maxSpeed = 80, .minSpeed = 70});
    chassis.moveToPose(-60, 42, 180, 1300, {.forwards = false, .maxSpeed = 80, .minSpeed = 70});

    chassis.moveToPoint(-60, 45, 600, {.forwards = false, .maxSpeed = 70}, false);
    LongGoal();
    pros::delay(2500);
    Intake();
    pros::delay(300);

    Loader.extend();

    chassis.moveToPoint(-59, 12, 3500, {.maxSpeed = 50});
    chassis.moveToPoint(-60, 45, 1300, {.forwards = false, .maxSpeed = 70}, false);
    LongGoal();
    pros::delay(2000);

    Intake();
    pros::delay(300);

    Loader.retract();

    chassis.moveToPose(-33, 12, 90, 3000, {.maxSpeed = 80}, false);
    Loader.extend();
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, 16, 2300, {.maxSpeed = 60});
}

// autonomous routines
void ElimRight() {
    chassis.setPose(15, 24, 0);
    Intake();

    chassis.moveToPoint(24, 49, 820);
    chassis.waitUntil(12);
    Loader.extend();
    chassis.moveToPose(47.5, 9, 180, 2600, {.lead = 0.4});

    chassis.moveToPoint(46.5, 37, 1400, {.forwards = false}, false);
    LongGoal();

    pros::delay(2000);
    Stop();
    Trap.retract();
    pros::delay(200);

    chassis.moveToPoint(46.5, 30, 650, {}, false);
    chassis.moveToPose(36.5, 35, 180, 2000, {.forwards = false, .lead = 0.4});

    // pros::delay(500);
    chassis.moveToPoint(36.5, 53, 5000, {.forwards = false}, false);
}

void ElimLeft() {
    chassis.setPose(-15, 24, 0);
    Intake();

    chassis.moveToPoint(-24, 49, 820);
    chassis.waitUntil(12);
    Loader.extend();
    chassis.moveToPose(-49, 9, -180, 2600, {.lead = 0.4});

    chassis.moveToPoint(-48, 37, 1400, {.forwards = false}, false);
    LongGoal();

    pros::delay(2000);
    Stop();
    Trap.retract();
    pros::delay(200);

    chassis.moveToPoint(-48, 30, 800, {}, false);
    chassis.moveToPose(-59, 35, -180, 3300, {.forwards = false, .lead = 0.4});
    chassis.moveToPoint(-59, 50, 5000, {.forwards = false}, false);
}

void QualiRight() {
    chassis.setPose(15, 24, 0);
    Intake();

    chassis.moveToPoint(27, 49, 1000, {.minSpeed = 120});
    chassis.waitUntil(12);
    Loader.extend();
    chassis.waitUntilDone();
    Loader.retract();

    chassis.moveToPose(53, 63.5, 60, 1000, {.lead = 0.5});
    chassis.waitUntil(13.5);
    Loader.extend();

    chassis.moveToPoint(30, 49, 700, {.forwards = false, .minSpeed = 120});
    chassis.moveToPoint(45, 34, 1200, {.forwards = false, .minSpeed = 120});
    chassis.moveToPose(51, 45, 180, 1200, {.forwards = false}, false);
    
    LongGoal();
    pros::delay(1700);
    Intake();
    pros::delay(200);
    chassis.moveToPoint(50, 20, 1000, {.minSpeed = 70});
    chassis.moveToPoint(50, 10, 1200, {.maxSpeed = 80});
    chassis.moveToPoint(50, 20, 1300, {.forwards = false});
}

void QualiLeft() {
    chassis.setPose(-15, 24, 0);
    Intake();

    chassis.moveToPoint(-27, 49, 1000, {.minSpeed = 70, .earlyExitRange = 2});

    chassis.moveToPose(-51, 63.5, -66, 1000, {.lead = 0.5, .maxSpeed = 70});

    chassis.waitUntil(13.5);
    Loader.extend();

    chassis.moveToPoint(-30, 49, 700, {.forwards = false, .minSpeed = 120});
    chassis.moveToPoint(-47, 34, 1200, {.forwards = false, .minSpeed = 120});
    chassis.moveToPose(-53.5, 45, -180, 1200, {.forwards = false}, false);

    LongGoal();
    pros::delay(1700);
    Intake();
    pros::delay(200);
    chassis.moveToPoint(-53, 12, 2300, {.maxSpeed = 80});

    chassis.moveToPose(-18, 59, 45, 1500, {.forwards = false});


    
}

void Counter7Left() {}


void SoloAWP() {
}



