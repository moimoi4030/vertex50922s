#include "globals.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep


lemlib::Drivetrain drivetrain (&left, 
                              &right, 
                              13, 
                              3.25, 
                              450,
                              8
);


// horizontal tracking wheel
lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_encoder, 2, 0);
// vertical tracking wheel
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder, 2, 0);

// odometry settings
lemlib::OdomSensors sensors(&vertical_tracking_wheel, // vertical tracking wheel 1
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            &horizontal_tracking_wheel, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);



lemlib::ControllerSettings lateral_controller(20, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              100, // derivative gain (kD)
                                              0, // anti windup
                                              1, // small error range, in inches
                                              90, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              250, // large error range timeout, in milliseconds
                                              10 // maximum acceleration (slew)
);


// angular PID controller
lemlib::ControllerSettings angular_controller(3, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              21, // derivative gain (kD)
                                              0, // anti windup
                                              3, // small error range, in degrees
                                              90, // small error range timeout, in milliseconds
                                              7, // large error range, in degrees
                                              250, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

// input curve for throttle input during driver control
lemlib::ExpoDriveCurve throttle_curve(5, // joystick deadband out of 127
                                     10,// minimum output where drivetrain will move out of 127
                                     1.05// expo curve
);

// input curve for steer input during driver control
lemlib::ExpoDriveCurve steer_curve(5, // joystick deadband out of 127
                                  5,// minimum output where drivetrain will move out of 127
                                  1// expo curve gain
);

// create the chassis
lemlib::Chassis chassis(drivetrain, // drivetrain settings
                        lateral_controller, // lateral PID settings
                        angular_controller, // angular PID settings
                        sensors, // odometry sensors
						&throttle_curve,
						&steer_curve
);