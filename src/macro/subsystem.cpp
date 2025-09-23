#include "helpers.hpp"
#include "main.h"
#include "color.hpp"
#include "globals.hpp"
#include "pros/rtos.hpp"

// intake vô hoard
void IntakeIntoHoard() {
    intake();
}

// score từ hoard ra low goal
void ScoreLowGoal() {
    stage1();
}

// score từ hoard ra mid goal
void ScoreHoardMidGoal(int scoreColor) {
    stage12.move(127);
    hoard.move(-127);
     
    while (true) {
        optical.set_led_pwm(100);
        if (detectColor() == scoreColor) {
            stage3.move(-127);
        } else if (detectColor() != scoreColor) {
            stage3.move(127);
            sup3.move(127);
        }
        pros::delay(20);
    }
    stop();
    return;
}

// score từ hoard ra long goal
void ScoreHoardLongGoal(int scoreColor) {
    stage12.move(127);
    hoard.move(-127);
     
    while (true) {
        optical.set_led_pwm(100);
        if (detectColor() == scoreColor) {
            stage3.move(127);
            sup3.move(-127);
        } else if (detectColor() != scoreColor) {
            stage3.move(127);
            sup3.move(127);
        }
        pros::delay(20);
    }
    stop();
    return;
}

// idle
void Idle() {
    stop();
}