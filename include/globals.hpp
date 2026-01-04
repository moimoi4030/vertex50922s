#pragma once

#include "globals.hpp"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "api.h"
#include "pros/abstract_motor.hpp"
#include "pros/adi.hpp"
#include "pros/motors.h"
#include "pros/optical.hpp"
#include "pros/vision.hpp"

// controller
inline pros::Controller master(pros::E_CONTROLLER_MASTER);

// drivetrain
inline pros::MotorGroup left({-3, -8, -10}, pros::MotorGearset::blue);
inline pros::MotorGroup right({4, 5, 9}, pros::MotorGearset::blue);

// subsystems
inline pros::Motor TopRoller(-19, pros::MotorGearset::blue);
inline pros::Motor MidRoller(7, pros::MotorGearset::blue);
inline pros::Motor IntakeRoller(11, pros::MotorGearset::blue);

// pneumatics
inline pros::adi::Pneumatics Loader('H', 0);
inline pros::adi::Pneumatics Trap('A', 0);
inline pros::adi::Pneumatics Wing('B', 0);

// sensors
inline pros::Optical optical(2);
inline pros::Imu imu(18);
inline pros::Rotation horizontal_encoder(16);
inline pros::Rotation vertical_encoder(-20);


extern lemlib::Drivetrain drivetrain;
extern lemlib::TrackingWheel horizontal_tracking_wheel;
extern lemlib::TrackingWheel vertical_tracking_wheel;
extern lemlib::OdomSensors sensors;
extern lemlib::ControllerSettings lateral_controller;
extern lemlib::ControllerSettings angular_controller;
extern lemlib::Chassis chassis;


