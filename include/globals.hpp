#pragma once

#include "lemlib/api.hpp" // IWYU pragma: keep
#include "api.h"
#include "pros/abstract_motor.hpp"
#include "pros/adi.hpp"
#include "pros/motors.h"
#include "pros/optical.hpp"

// controller
inline pros::Controller master(pros::E_CONTROLLER_MASTER);

// drivetrain
inline pros::MotorGroup left({-1, -14, -15}, pros::MotorGearset::blue);
inline pros::MotorGroup right({16, 17, 10}, pros::MotorGearset::blue);

// subsystems
inline pros::Motor stage12(8, pros::MotorGearset::blue);
inline pros::Motor stage3(9, pros::MotorGearset::blue);
inline pros::Motor sup3(11, pros::MotorGearset::blue);
inline pros::Motor hoard(12, pros::MotorGearset::blue);

// pneumatics
inline pros::adi::Pneumatics descore('H', 0);
inline pros::adi::Pneumatics loader('E', 0);
inline pros::adi::Pneumatics supIntake('A', 0);

// sensors
inline pros::Optical optical(20);
inline pros::Imu imu(19);
inline pros::Rotation horizontal_encoder(-18);
inline pros::Rotation vertical_encoder(-13);


extern lemlib::Drivetrain drivetrain;
extern lemlib::TrackingWheel horizontal_tracking_wheel;
extern lemlib::TrackingWheel vertical_tracking_wheel;
extern lemlib::OdomSensors sensors;
extern lemlib::ControllerSettings lateral_controller;
extern lemlib::ControllerSettings angular_controller;
extern lemlib::Chassis chassis;


