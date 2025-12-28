#include "autons.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "main.h"
#include "globals.hpp"
#include "macro/color.hpp"
#include "helpers.hpp"


// test   
void Test() {
    chassis.setPose(0, 0, 180);
    chassis.swingToHeading(-90, DriveSide::RIGHT, 1000, {}, false);
    chassis.setPose(0, 0, -90);
    Intake();
    chassis.moveToPoint(0, 17, 2500, {.maxSpeed = 70});
}

// autonomous routines
void RightLong7Rush() {
    chassis.setPose(15, 24, 0);
    Intake();
    Wing.extend();

    chassis.moveToPoint(24, 49, 820);
    chassis.waitUntil(12);
    Loader.extend();
    chassis.moveToPose(49, 8, 180, 2700, {.lead = 0.4});

    chassis.moveToPoint(48, 37, 1400, {.forwards = false}, false);
    LongGoal();

    pros::delay(2000);
    Stop();
    Trap.retract();

    chassis.moveToPoint(48, 28, 800, {}, false);
    chassis.moveToPose(37.5, 35, 180, 1600, {.forwards = false, .lead = 0.4});
    chassis.moveToPoint(36, 50, 5000, {.forwards = false}, false);
}

void LeftLong7Rush() {}


void LeftLongMid() {
    chassis.setPose(-15, 24, 0);
    Intake();

    chassis.moveToPoint(-24, 49, 1000, {.minSpeed = 70, .earlyExitRange = 2}, false);

    chassis.moveToPose(-49.5, 62.3, -70, 1100, {.lead = 0.5, .maxSpeed = 80});
    chassis.waitUntilDone();
    Loader.extend();

    chassis.moveToPoint(-23, 49, 700, {.forwards = false});

    chassis.turnToPoint(-13, 55.6, 500, {.forwards = false});
    chassis.moveToPoint(-13, 55.6, 300, {.forwards = false}, false);
    MidGoal();
    pros::delay(1000);
    Intake();
    pros::delay(200);

    chassis.moveToPoint(-46, 24, 1200, {.minSpeed = 120});
    chassis.moveToPose(-48.5, 10, 180, 1500, {.lead = 0.5});
    chassis.moveToPoint(-46, 40, 1100, {.forwards = false}, false);
    LongGoal();

    pros::delay(2000);
    Stop();
    Wing.extend();

    chassis.swingToPoint(-34, 32, DriveSide::LEFT, 800, {.minSpeed = 120, .earlyExitRange = 4});
    chassis.moveToPoint(-34, 32, 900);
    chassis.turnToHeading(180, 700);
    chassis.moveToPoint(-32.5, 55, 1300, {.forwards = false});
    chassis.waitUntil(6);
    Wing.retract();
}

void soloAWP() {
    
}



void skill() {
    chassis.setPose(15, 24, 0);
    Intake();

    chassis.moveToPoint(24, 49, 1500, {.maxSpeed = 80});
    chassis.moveToPose(49, 15, 180, 1500, {.lead = 0.4, .maxSpeed = 80});
    Loader.extend();
    chassis.moveToPoint(49, 11, 1000, {.maxSpeed = 60});
    pros::delay(3000);

    chassis.moveToPoint(49, 20, 900, {.forwards = false, .maxSpeed = 80, .minSpeed = 80}, false);
    Stop();

    chassis.moveToPoint(56, 40, 1200, {.forwards = false, .maxSpeed = 80, .minSpeed = 70});
    Loader.retract();

    chassis.moveToPose(56, 90, 180, 5000, {.forwards = false, .maxSpeed = 80, .minSpeed = 70});
    chassis.moveToPoint(46.5, 110, 3000, {.forwards = false, .maxSpeed = 80, .minSpeed = 70});

    chassis.turnToHeading(0, 1000, {}, false);

    chassis.setPose(49, 110, 0);
    chassis.moveToPoint(49, 95, 1000, {.forwards = false, .maxSpeed = 70}, false);
    LongGoal();

    pros::delay(2500);
    Intake();
    pros::delay(200);

    Loader.extend();

    chassis.moveToPoint(49, 124, 1500, {.maxSpeed = 60});
    pros::delay(2000);

    chassis.moveToPoint(49, 95, 1300, {.forwards = false, .maxSpeed = 70}, false); 
    LongGoal();

    pros::delay(1700);
    Intake();
    pros::delay(200);

    chassis.moveToPoint(49, 110, 1000, {.maxSpeed = 80});

    
    Intake();
    Loader.retract();
    chassis.moveToPoint(27, 90, 1500, {.maxSpeed = 80, .minSpeed = 70});
    chassis.moveToPoint(19, 45, 2000, {.maxSpeed = 80, .minSpeed = 70});

    chassis.moveToPoint(-21, 45, 1500, {.maxSpeed = 80});
    chassis.waitUntilDone();
    Loader.extend();

    chassis.turnToPoint(-12.5, 57, 1000, {.forwards = false});
    chassis.moveToPoint(-12.5, 57, 1000, {.forwards = false, .maxSpeed = 70});
    MidGoal();

    pros::delay(3000);
    Intake();
    pros::delay(200);

    chassis.moveToPoint(-26, 55, 2000, {.maxSpeed = 80});
    Loader.retract();

    chassis.moveToPose(-26, 95, 0, 6000, {.maxSpeed = 80});

    /*chassis.moveToPoint(-55, 115, 2000, {.maxSpeed = 80});
    chassis.turnToHeading(0, 2000);

    Loader.extend();
    chassis.moveToPoint(-57, 128, 1000, {.maxSpeed = 70});
    pros::delay(3000);

    chassis.moveToPoint(-40, 100, 2500, {.forwards = false, .maxSpeed = 80, .minSpeed = 70});
    Loader.retract();

    chassis.moveToPose(-38, 44, 0, 5000, {.forwards = false, .maxSpeed = 80, .minSpeed = 70});
    chassis.moveToPoint(-53.5, 25, 2000, {.forwards = false, .maxSpeed = 80});
    chassis.turnToHeading(180, 1000);
    chassis.moveToPoint(-55.5, 38, 1000, {.forwards = false, .maxSpeed = 70});

    LongGoal();

    pros::delay(3000);
    Intake();
    pros::delay(200);

    chassis.moveToPoint(-53, 10, 1500, {.maxSpeed = 60});
    pros::delay(3000);
    chassis.moveToPoint(-55.5, 38, 2000, {.forwards = false, .maxSpeed = 70});

    LongGoal();
    pros::delay(3000);
    Intake();
    pros::delay(200);*/
}