/**
 * 2026 Pushback Tournament
 * Team 938G Coder ARM
 * Pros ProsImp.h
 */

//Includes api.h.
#include "api.h"
#include "lemlib/api.hpp"
#include "pros/distance.hpp"
#ifndef _PROS_IMP_H_
#define _PROS_IMP_H_

//- Declare objects as initialization.

//Declare controller and other general objects.
extern pros::Controller MasterCont;

//Declare 6 motor drivetrain with left and right motor groups.
extern pros::Motor LFwheel;
extern pros::Motor LMwheel;
extern pros::Motor LBwheel;
extern pros::Motor RFwheel;
extern pros::Motor RMwheel;
extern pros::Motor RBwheel;

extern pros::MotorGroup LMotorGroup;
extern pros::MotorGroup RMotorGroup;

extern lemlib::Drivetrain drivetrain;
extern lemlib::Chassis chassis;

//Declare block processing flywheels as motors separated by height.
extern pros::Motor TFlywheel;
extern pros::Motor BFlywheel;

//Declare pneumatics.
extern pros::adi::Pneumatics PneumaticDescore;
extern pros::adi::Pneumatics PneumaticLoad;
extern pros::adi::Pneumatics PneuOuttake;

//Declare sensors and odom.
extern pros::Imu IMU;
extern pros::Rotation VerticalSensor;
extern lemlib::TrackingWheel VerticalTracking;
extern lemlib::OdomSensors OSensors;

//Declare extra opcontrol lemlib.
extern lemlib::ExpoDriveCurve ThrottleCurve;
extern lemlib::ExpoDriveCurve SteerCurve;

//Declare PID.
extern lemlib::ControllerSettings LController;
extern lemlib::ControllerSettings AController;

extern pros::Distance frontDistanceSensor;
extern pros::Distance backDistanceSensor;
extern pros::Distance leftDistanceSensor;
extern pros::Distance rightDistanceSensor;
extern pros::Distance outtakeDistanceSensor;
extern pros::Distance intakeDistanceSensor;


#endif //_PROS_IMP_H_