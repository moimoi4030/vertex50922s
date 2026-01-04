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
			
			// motors torque
			pros::lcd::print(3, "Motor torque(front, mid, back)");
			pros::lcd::print(4, "Left: %.2f", left.get_torque()); // left
            pros::lcd::print(5, "Right: %.2f", right.get_torque()); // right

			// motors velocity
			pros::lcd::print(6, "Motor velocity(front, mid, back)");
			pros::lcd::print(7, "Left: %.2f", left.get_actual_velocity()); // left
            pros::lcd::print(8, "Right: %.2f, %.2f, %.2f", right.get_actual_velocity()); // right

			// motors current draw
			pros::lcd::print(9, "Motor current draw(front, mid, back)");
			pros::lcd::print(10, "Left: %.2f", left.get_current_draw()); // left
            pros::lcd::print(11, "Right: %.2f", right.get_current_draw()); // right

            // delay to save resources
            pros::delay(100);
        }
    }); 
	IntakeRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	MidRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
	TopRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
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
	//ElimRight();
	//ElimLeft();
	//QualiLeft();
	QualiRight();
	//Test();
	// skill();
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
		optical.set_led_pwm(100);
		/*switch (currentMode) {
			case 0:
				master.set_text(2, 1, "RED");
				blueSort();
				break;
			case 1:
				master.set_text(2, 1, "BLUE");
				redSort();
				break;
		}*/

		// get left y and right y positions
		int Power = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);  
        int Turn  = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X); 

        chassis.arcade(Power, 0.7 *Turn, 1, 0.45);
		
		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
			currentMode += 1;
			if(currentMode == 2) {
				currentMode = 0;
			}
		}
		
		// loader
		if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
			Loader.toggle();
		}
		
		// trap
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
			Wing.retract();
		} else {
			Wing.extend();
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