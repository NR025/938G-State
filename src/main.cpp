/**
 * 2026 Pushback Tournament
 * Team 938G Coder ARM()
 * Lem main.cpp
 */

//#We include main.h and LemImp, Op, and Auton.
#include "lemlib/api.hpp"
#include "main.h"
#include "Lem_Initialize.h"
#include "LemOpUtils.h"
#include "LemAuton.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

void initialize() {

	/*# This commented code in initialize tells us the code program and the lemlib pose
	the robot thinks its at. Only turn on for testing */

	pros::lcd::initialize();
	//pros::lcd::print(7, "ARM, AutonS, 2/14");

	//# Calibrate the chassis.
	chassis.calibrate();

	//pros::lcd::print(0, "Robot 938G initialized");
	/*
    pros::Task screenTask([&]() {

		lemlib::TrackingWheel leftMotor(drivetrain.leftMotors, drivetrain.wheelDiameter,
                                                      -(drivetrain.trackWidth / 2), drivetrain.rpm);
		lemlib::TrackingWheel rightMotor(drivetrain.rightMotors, drivetrain.wheelDiameter,
                                                      -(drivetrain.trackWidth / 2), drivetrain.rpm);
        while (true) {
            // print robot location to the brain screen
    		lemlib::Pose pose = chassis.getPose();
   			pros::lcd::print(1, "Chassis Pos X: %.2f, Y: %.2f, H: %.2f", pose.x, pose.y, pose.theta);

			// print traction wheel
			pros::lcd::print(2, "LMotors AvgD: %.2f", leftMotor.getDistanceTraveled());
			pros::lcd::print(3, "RMotors AvgD: %.2f", rightMotor.getDistanceTraveled());

			// print tracking wheel
			//pros::lcd::print(4, "TrackWheel D: %.2f", VerticalTracking.getDistanceTraveled());

			// print IMU
			pros::lcd::print(5, "IMU H: %.2f, R: %.2f", OSensors.imu->get_heading(), lemlib::radToDeg(OSensors.imu->get_rotation()));

			// Reset Pose button B
			if (MasterCont.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
        		chassis.setPose(0,0,0, false);
				leftMotor.reset();
				rightMotor.reset();
				//VerticalTracking.reset();
    		} 

            // delay to save resources
            pros::delay(100);
        }
    });
	*/
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomousS or opcontrol. When
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

void squareTest() {
	chassis.setPose(0, 0, 0);
	chassis.moveToPoint(0, 18, 1000);
	chassis.turnToHeading(90, 3000);
	chassis.waitUntilDone();
	chassis.moveToPoint(18, 18, 1000);
	chassis.turnToHeading(180, 3000);
	chassis.waitUntilDone();
	chassis.moveToPoint(18, 0, 1000);
	chassis.turnToHeading(270, 3000);
	chassis.waitUntilDone();
	chassis.moveToPoint(0, 0, 1000);
	chassis.turnToHeading(0, 3000);
	chassis.waitUntilDone();
}

void testTurn()	{
	chassis.setPose(0, 0, 0);
	chassis.turnToHeading(90, 3000);
	chassis.waitUntilDone();
	chassis.turnToHeading(180, 3000);
	chassis.waitUntilDone();
	chassis.turnToHeading(270, 3000);
	chassis.waitUntilDone();
	chassis.turnToHeading(0, 3000);
	chassis.waitUntilDone();
}

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
	//# State the path.
	//_PathLemSkills();
	_MovementWithDistanceSensor();
	//testTurn();
	//squareTest();

	/*
	while(true){
 	   int dist = distance_sensor.get();
       pros::lcd::print(2, "Distance: %d", dist);
       pros::delay(20);
	}
	*/
}



/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 * If no competition control is connected,
 *  this function will run immediately
 * following initialize().
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */


void opcontrol() {

	pros::Task BlockTask ([&] {
		while (true) {

			//#Block movement functions called.
			BlockMovement();		

			//#15 millisecond rest.
			pros::delay(15);
		}
	});

	pros::Task PneuTask ([&] {

		while (true) {

			while (true) {

				//# Pneumatic functions called.
				PneuMovement();

				//# 15 millisecond rest.
				pros::delay(15);
			
			}

		}

	});

	while (true) {

		//# Opcontrol functions called.
		DriveMovement();		

		//#15 millisecond rest.
		pros::delay(15);
	}
	
}
