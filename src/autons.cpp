#include "autons.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "main.h"
#include "globals.hpp"
#include "macro/color.hpp"
#include "helpers.hpp"


// test   
void Test() {

}

// autonomous routines
void Long7Rush() {
    chassis.setPose(15, 24, 0);
    Intake();

    chassis.moveToPoint(24, 49, 850);
    chassis.waitUntil(12);
    Loader.extend();
    /*chassis.turnToPoint(44.5, 24, 700);

    chassis.moveToPoint(44.5, 24, 1200, {.minSpeed = 120});*/
    chassis.moveToPose(48, 10, 180, 3200, {.lead = 0.4});

    chassis.moveToPoint(48, 38, 1100, {.forwards = false}, false);
    LongGoal();

    pros::delay(3000);
    Stop();
    Wing.extend();

    chassis.moveToPoint(39.5, 36.5, 1000);
    chassis.moveToPose(39.5, 55, 180, 5000, {.forwards = false, .lead = 0.1});
    chassis.waitUntil(10);
    Wing.retract();
    
    

    /*chassis.setPose(0, 17, 0); // bắt đầu
    intake();

    chassis.moveToPose(10, 42, 27, 1000); // 3 banh
    chassis.waitUntil(15.3);
    loader.extend();
    chassis.waitUntilDone();
    pros::delay(300);
    loader.retract();


    chassis.turnToHeading(130, 700);

    chassis.moveToPoint(35, 14, 1200);
    chassis.turnToHeading(180, 700);
    loader.extend();
    chassis.waitUntilDone();
    chassis.setPose(35, 15, 180);

    chassis.moveToPoint(35, 0, 850, {.maxSpeed = 100});

    chassis.waitUntilDone();
    chassis.getPose();
    chassis.moveToPoint(35, 20, 700, {.forwards = false});
    chassis.waitUntilDone();
    
    loader.retract();
    chassis.turnToHeading(-11, 900);
    chassis.waitUntilDone();


    chassis.moveToPoint(chassis.getPose().x - 2.3, 36, 1100);
    chassis.waitUntilDone();
    longGoal();

    pros::delay(3200);
    descore.extend();
    chassis.swingToHeading(-90, DriveSide::RIGHT, 700, {.minSpeed = 100, .earlyExitRange = 11});
    chassis.moveToPose(45.7, 55, 176, 1500, {.forwards = false});
    chassis.waitUntil(30);
    descore.retract();

    chassis.waitUntilDone();
    chassis.turnToHeading(-115, 1000);*/
}

void Long8Center1() {
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

    chassis.moveToPoint(22.7, 49, 1000, {}, false);
    Loader.extend();
    chassis.turnToPoint(49.5, 20, 600);

    chassis.moveToPoint(49.5, 20, 800, {.minSpeed = 50});
    chassis.moveToPose(49.5, 10, 180, 1500, {.lead = 0.2, .maxSpeed = 70}, false);

    chassis.moveToPoint(49.5, 39, 1100, {.forwards = false}, false);
    Wing.extend();
    LongGoal();
}