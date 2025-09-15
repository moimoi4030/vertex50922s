#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep


lemlib::Drivetrain drivetrain (&left, // left motor group
                              &right, // right motor group
                              15, // 10 inch track width
                              3.25, // using new 4" omnis
                              333.33, // drivetrain rpm is 360
                              8// horizontal drift is 2 (for now)
);


// horizontal tracking wheel
lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_encoder, 2, -6.75);
// vertical tracking wheel
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_encoder, 2, -1.25);

// odometry settings
lemlib::OdomSensors sensors(&vertical_tracking_wheel, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            &horizontal_tracking_wheel, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);

// lateral PID controller
lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              3, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              20 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller(2, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              10, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in degrees
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in degrees
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

// input curve for throttle input during driver control
lemlib::ExpoDriveCurve throttle_curve(5, // joystick deadband out of 127
                                     10,// minimum output where drivetrain will move out of 127
                                     1.05// expo curve
);

// input curve for steer input during driver control
lemlib::ExpoDriveCurve steer_curve(5, // joystick deadband out of 127
                                  10,// minimum output where drivetrain will move out of 127
                                  1.2// expo curve gain
);

// create the chassis
lemlib::Chassis chassis(drivetrain, // drivetrain settings
                        lateral_controller, // lateral PID settings
                        angular_controller, // angular PID settings
                        sensors,// odometry sensors
						&throttle_curve,
						&steer_curve
);