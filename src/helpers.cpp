#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "globals.hpp"
#include "helpers.hpp"


// subsystem driver control

void intake() {
  stage12.move_velocity(600);
  stage3.move_velocity(600);
  hoard.move(0);
  sup3.move_velocity(600);
  supIntake.retract();
}

void stage1() {
  stage12.move_velocity(-600);
  hoard.move_velocity(-600);
  sup3.move_velocity(600);
}

void stage2() {
  stage12.move_velocity(600);
  stage3.move_velocity(-600);
  hoard.move_velocity(-500);
  sup3.move_velocity(270);
}

void longGoal() {
  stage12.move_velocity(600);
  stage3.move_velocity(600);
  hoard.move_velocity(-600);
  sup3.move_velocity(600);
  supIntake.extend();
}

void intakeHold() {
  stage12.move_velocity(600);
  stage3.move_velocity(0);
  hoard.move(0);
  sup3.move_velocity(-600);
}

void preLongGoal() {
  stage12.move_velocity(600);
  stage3.move_velocity(600);
  hoard.move_velocity(0);
  sup3.move_velocity(600);
  supIntake.extend();
}

void stop() {
  stage12.move(0);
  stage3.move(0);
  sup3.move(0);
  hoard.move(0);
}



