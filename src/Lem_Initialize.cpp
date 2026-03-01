/**
 * 2026 Pushback Tournament
 * Team 938G Coder ARM
 * Pros ProsImp.cpp
 */

//Includes Pros.Imp.
#include "Lem_Initialize.h"

//- Define objects as initialization.

//Define controller and other general objects.
pros::Controller MasterCont (pros::E_CONTROLLER_MASTER);

/* test robot definition starts here

//Define 6 motor drivetrain with left and right motor groups. 
pros::Motor LFwheel (-14, 
					pros::v5::MotorGears::green);
//pros::Motor LMwheel (0, 
//					pros::v5::MotorGears::green);
pros::Motor LBwheel (-12, 
					pros::v5::MotorGears::green);
pros::Motor RFwheel (16,
					pros::v5::MotorGears::green);
//pros::Motor RMwheel (0,
//					pros::v5::MotorGears::green);
pros::Motor RBwheel (11, 
					pros::v5::MotorGears::green);

pros::MotorGroup LMotorGroup ({-14, -12}, 
							 pros::v5::MotorGearset::green);
pros::MotorGroup RMotorGroup ({16, 11}, 
							 pros::v5::MotorGearset::green);

lemlib::Drivetrain drivetrain (&LMotorGroup, 
							  &RMotorGroup, 
							  10,
							  lemlib::Omniwheel::NEW_4,
							  280,
							  2);

//Define block processing flywheels as motors separated by height.
pros::Motor TFlywheel (1);
pros::Motor MFlywheel (2);
pros::Motor BFlywheel (3);

//Defines sensors and odom
pros::Imu IMU(10);
pros::Rotation VerticalSensor(1);
lemlib::TrackingWheel VerticalTracking(&VerticalSensor, 2.75, 6);

lemlib::OdomSensors OSensors (nullptr,
							//nullptr,
							  &VerticalTracking,
	                          nullptr,
							  nullptr,
							  &IMU);

//Defines extra opcontrol lemlib.
lemlib::ExpoDriveCurve ThrottleCurve (3,
                                     10,
                                     1.019);
lemlib::ExpoDriveCurve SteerCurve (3,
                                  10,
                                  1.019);

//Defines PID.
lemlib::ControllerSettings LController (8, // proportional gain (kP)
                                        0, // integral gain (kI)
                                        3, // derivative gain (kD)
                                        3, // anti windup
                        
										1, // small error range, in inches
                                        100, // small error range timeout, in milliseconds
										3, // large error range, in inches
										500, // large error range timeout, in milliseconds
										20 // maximum acceleration (slew)
);
lemlib::ControllerSettings AController (2, // proportional gain (kP)
										0, // integral gain (kI)
										20, // derivative gain (kD)
										3, // anti windup
										1, // small error range, in degrees
										100, // small error range timeout, in milliseconds
										3, // large error range, in degrees
										500, // large error range timeout, in milliseconds
										0 // maximum acceleration (slew)
);

//Define pneumatics.
pros::adi::Pneumatics PneumaticDescore('b', false);
pros::adi::Pneumatics PneuLoad('d', true);

lemlib::Chassis chassis (drivetrain,
						LController,
						AController,
						OSensors);
*/



// Competition robot definition starts here.

//Define 6 motor drivetrain with left and right motor groups. 
pros::Motor LFwheel (-13, 
					pros::v5::MotorGears::blue);
pros::Motor LMwheel (-12, 
					pros::v5::MotorGears::blue);
pros::Motor LBwheel (-11, 
					pros::v5::MotorGears::blue);
pros::Motor RFwheel (18,
					pros::v5::MotorGears::blue);
pros::Motor RMwheel (19,
					pros::v5::MotorGears::blue);
pros::Motor RBwheel (20, 
					pros::v5::MotorGears::blue);

pros::MotorGroup LMotorGroup ({-13, -12, -11}, 
							 pros::v5::MotorGearset::blue);
pros::MotorGroup RMotorGroup ({18, 19, 20}, 
							 pros::v5::MotorGearset::blue);

lemlib::Drivetrain drivetrain (&LMotorGroup, 
							  &RMotorGroup, 
							  11,
							  3.25,
							  360,
							  2);

//Define block processing flywheels as motors separated by height.
pros::Motor TFlywheel (-5);
pros::Motor BFlywheel (9);

//Define pneumatics.
pros::adi::Pneumatics PneumaticDescore('b', true);
pros::adi::Pneumatics PneumaticLoad('d', false);
pros::adi::Pneumatics PneuOuttake('a', false);

//Defines sensors and odom
pros::Imu IMU(10);
pros::Rotation VerticalSensor(1);
lemlib::TrackingWheel VerticalTracking(&VerticalSensor, 2.75, 6);

// Define distance sensors
pros::Distance backDistanceSensor(3);
pros::Distance frontDistanceSensor(21);
pros::Distance leftDistanceSensor(15);
pros::Distance rightDistanceSensor(16);
pros::Distance outtakeDistanceSensor(14);
pros::Distance intakeDistanceSensor(1);

lemlib::OdomSensors OSensors (nullptr,
							  nullptr,
							  //&VerticalTracking,
	                          nullptr,
							  nullptr,
							  &IMU);

//Defines extra opcontrol lemlib.
/*
lemlib::ExpoDriveCurve ThrottleCurve (3,
                                     10,
                                     1.019);
lemlib::ExpoDriveCurve SteerCurve (3,
                                  10,
                                  1.019);
*/

//Defines PID.
lemlib::ControllerSettings LateralPID (15, // 15 proportional gain (kP)
                                        0, // integral gain (kI)
                                        75, // 75 derivative gain (kD)
                                        0, // anti windup
                                    	0.5, // small error range, in inches
                                        100, // small error range timeout, in milliseconds
										1, // large error range, in inches
										500, // large error range timeout, in milliseconds
										20 // maximum acceleration (slew)
);

lemlib::ControllerSettings TurningPID (8, // proportional gain (kP)
										0, // integral gain (kI)
										78, // derivative gain (kD)
										0, // anti windup
										1.5, // small error range, in degrees
										100, // small error range timeout, in milliseconds
										4, // large error range, in degrees
										500, // large error range timeout, in milliseconds
										0 // maximum acceleration (slew)
);

lemlib::Chassis chassis (drivetrain,
						LateralPID,
						TurningPID,
						OSensors);
//


/*
lemlib::ControllerSettings LController (4, // proportional gain (kP)
                                        -1, // integral gain (kI)
                                        20, // derivative gain (kD)
                                        3, // anti windup
                                    	1, // small error range, in inches
                                        100, // small error range timeout, in milliseconds
										3, // large error range, in inches
										500, // large error range timeout, in milliseconds
										20 // maximum acceleration (slew)
);


lemlib::ControllerSettings AControllerOLD (8, // proportional gain (kP)
										0, // integral gain (kI)
										100, // derivative gain (kD)
										3, // anti windup
										1, // small error range, in degrees
										100, // small error range timeout, in milliseconds
										3, // large error range, in degrees
										500, // large error range timeout, in milliseconds
										0 // maximum acceleration (slew)
);



*/