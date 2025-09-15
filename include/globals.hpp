#pragma once

#include "lemlib/api.hpp" // IWYU pragma: keep
#include "api.h"
#include "pros/adi.hpp"
#include "pros/optical.hpp"
#include "pros/ai_vision.hpp"

// controller
inline pros::Controller master(pros::E_CONTROLLER_MASTER);

// drivetrain
inline pros::MotorGroup left({1, -2, -5});
inline pros::MotorGroup right({6, -7, 10});

// subsystems
inline pros::Motor stage12(11);
inline pros::Motor stage3(14);
inline pros::Motor sup3(13);
inline pros::Motor hoard(16);

// pneumatics
inline pros::adi::Pneumatics sortAlign('A', 0);
inline pros::adi::Pneumatics loader('B', 0);

// sensors
inline pros::Optical optical(20);
inline pros::Imu imu(10);
inline pros::Rotation horizontal_encoder(20);
inline pros::Rotation vertical_encoder(21);
inline pros::AIVision vision(22);


extern lemlib::Drivetrain drivetrain;
extern lemlib::TrackingWheel horizontal_tracking_wheel;
extern lemlib::TrackingWheel vertical_tracking_wheel;
extern lemlib::OdomSensors sensors;
extern lemlib::ControllerSettings lateral_controller;
extern lemlib::ControllerSettings angular_controller;
extern lemlib::Chassis chassis;


