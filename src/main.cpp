#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "autons.hpp"
#include "macro/color.hpp"
#include "macro/subsystem.hpp"
#include "globals.hpp"
#include "helpers.hpp"

int selectColor = 1;

// initialize function. Runs on program startup
void initialize() {
    pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(); // calibrate sensors
    // print position to brain screen
    pros::Task screentask ([&]() {
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading

			if(selectColor == 0) {
				pros::lcd::print(4, "NONE");
			} else if(selectColor == 1) {
				pros::lcd::print(4, "RED");
			} else if(selectColor == 2) {
				pros::lcd::print(4, "BLUE");
			}
            // delay to save resources
            pros::delay(10);
			
        }
    });
}
/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */



void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */



void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */


void autonomous() {
  
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol() {
	// local
	int currPower = 0;
	while (true) {
		optical.set_led_pwm(100);

		// get left y and right y positions
		float power = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		float turn = 0.7 * master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
		// move
		int rampPower = (power - currPower) * 0.2;
		currPower += rampPower;
		chassis.arcade(currPower, turn, 1, 0.25);
		
		if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
			autonomous();
		}
		
		// loader
		if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
			loader.toggle();
		}
		
		// sort + align	
		if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
			sortAlign.toggle();
		}
		
		// intake
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
			intake();
			sortAlign.extend();
		// stage 1
		} else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
			stage1();
		// stage 2
		} else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
			stage2();
			sortAlign.retract();
		// stage 3
		} else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
			longGoal();
			sortAlign.retract();
		} else {
			stop();
		}
	}
	pros::delay(10);                              // Run for 10 ms then update
}
