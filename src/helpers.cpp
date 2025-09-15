#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "globals.hpp"
#include "pros/ai_vision.h"
#include "pros/ai_vision.hpp"
#include "helpers.hpp"


// subsystem driver control

void intake() {
  stage12.move(127);
  stage3.move(127);
  hoard.move(0);
  sup3.move(127);
}

void stage1() {
  stage12.move(-127);
  hoard.move(-127);
}

void stage2() {
  stage12.move(127);
  stage3.move(-70);
  hoard.move(-127);
}

void longGoal() {
  stage12.move(127);
  stage3.move(127);
  sup3.move(-127);
  hoard.move(-127);
}

void stop() {
  stage12.move(0);
  stage3.move(0);
  sup3.move(0);
  hoard.move(0);
}




