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
inline pros::MotorGroup left({-16, -17, -19}, pros::MotorGearset::blue);
inline pros::MotorGroup right({5, 9, 20}, pros::MotorGearset::blue);

// subsystems
inline pros::Motor TopRoller(-6, pros::MotorGearset::blue);
inline pros::Motor MidRoller(4, pros::MotorGearset::blue);
inline pros::Motor IntakeRoller(8, pros::MotorGearset::blue);

// pneumatics
inline pros::adi::Pneumatics Loader('A', 0);
inline pros::adi::Pneumatics Trap('B', 0);
inline pros::adi::Pneumatics Wing('C', 0);

// sensors
inline pros::Optical optical(2);
inline pros::Imu imu(7);
inline pros::Rotation horizontal_encoder(1);
inline pros::Rotation vertical_encoder(-18);


extern lemlib::Drivetrain drivetrain;
extern lemlib::TrackingWheel horizontal_tracking_wheel;
extern lemlib::TrackingWheel vertical_tracking_wheel;
extern lemlib::OdomSensors sensors;
extern lemlib::ControllerSettings lateral_controller;
extern lemlib::ControllerSettings angular_controller;
extern lemlib::Chassis chassis;


