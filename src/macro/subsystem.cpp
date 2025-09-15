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
void ScoreHoardMidGoal(int scoreColor, int scoreBlocks) {
    int detectBlocks = 0;
    stage12.move(127);
    hoard.move(-127);

    while (detectBlocks <= scoreBlocks) {
        if (detectColor() == scoreColor) {
            stage3.move(-70);

            pros::delay(300);
            stage3.move(0);
            detectBlocks++;
        } else {
            stage3.move(127);
            sup3.move(127);

            pros::delay(300);
            stage3.move(0);
            sup3.move(0);
        }
        pros::delay(10); 
    }

    stop();
    return;
}

// score từ hoard ra long goal
void ScoreHoardLongGoal(int scoreColor, int scoreBlocks) {
    int detectBlocks = 0;
    stage12.move(127);
    hoard.move(127);

    while (detectBlocks <= scoreBlocks) {
        if (detectColor() == scoreColor) {
            stage3.move(127);
            sup3.move(-127);

            pros::delay(300);
            stage3.move(0);
            sup3.move(0);
            detectBlocks++;
        } else {
            stage3.move(127);
            sup3.move(127);

            pros::delay(300);
            stage3.move(0);
            sup3.move(0);
        }
        pros::delay(10); 
    }

    stop();
    return;
}

// idle
void Idle() {
    stop();
}