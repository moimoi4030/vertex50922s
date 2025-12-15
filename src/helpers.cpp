#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "globals.hpp"
#include <time.h>
#include "helpers.hpp"

// subsystem driver control

void Intake() {
  IntakeRoller.move_velocity(600);
  MidRoller.move_velocity(600);
  TopRoller.move_velocity(200);
  Trap.retract();
}

void LowGoal() {
  IntakeRoller.move_velocity(-600);
  MidRoller.move_velocity(-600);
  TopRoller.move_velocity(-300);
}

void MidGoal() {
  IntakeRoller.move_velocity(300);
  MidRoller.move_velocity(300);
  TopRoller.move_velocity(-150);
}

void LongGoal() {
  TopRoller.move_velocity(600);
  MidRoller.move_velocity(600);
  IntakeRoller.move_velocity(600);
  Trap.extend();
}

void Stop() {
  IntakeRoller.move_velocity(0);
  MidRoller.move_velocity(0);
  TopRoller.move_velocity(0);
}



