#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "autons.hpp"
#include "globals.hpp"
#include "helpers.hpp"
#include "macro/color.hpp"
#include "pros/abstract_motor.hpp"
#include "pros/misc.h"
#include "pros/motors.h"

// initialize function. Runs on program startup
void initialize() {
    pros::lcd::initialize(); // initialize brain screen
    chassis.calibrate(true); // calibrate sensors
	pros::Task task([&]() {
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading

			lemlib::telemetrySink()->info("Chassis pose: {}", chassis.getPose());
			
            // delay to save resources
            pros::delay(100);
        }
    }); 
	IntakeRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	MidRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	TopRoller.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
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
	left.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	right.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	Long7Rush();
	//Long8Center1();
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
	int currentMode = 0;

	while (true) {
		/*switch (currentMode) {
			case 0:
            	offSort();
				master.clear_line(2);
				master.print(2, 1, "OFF");
            	break;
			case 1:
            	blueSort();
				master.clear_line(2);
				master.print(2, 1, "RED");
            	break;
			case 2:
        		redSort();
				master.clear_line(2);
				master.print(2, 1, "BLUE");
            	break;
		}*/

		// get left y and right y positions
		int Power = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);  
        int Turn  = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X); 

        chassis.arcade(Power, Turn, 1, 0.45);
		
		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
			currentMode += 1;
			if(currentMode == 3) {
				currentMode = 0;
			}
		}

		if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
			autonomous();
		}
		
		// loader
		if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
			Loader.toggle();
		}
		
		// wing
		if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
			Wing.toggle();
		}
		
		// long goal
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
			LongGoal();
		// low goal
		} else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
			LowGoal();
		// mid goal
		} else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
			MidGoal();
		// intake
		} else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
			Intake();
		} else {
			Stop();
		}
		pros::delay(10);
	}
}
