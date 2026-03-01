/**
 * 2026 Pushback Tournament
 * Team 938G Coder ARM
 * Pros ProsAuton.cpp
 */

//Include initialized devices and ProsAuton.h.
#include "Lem_Initialize.h"
#include "LemAuton.h"

//#Define auton utility variables.

//Define auton functions.
void _LateralMovement (float XCoord, float YCoord, int Time, bool Forward=true) {

    chassis.moveToPoint(XCoord, YCoord, Time, {.forwards = Forward, .maxSpeed = 127, .minSpeed = 0, .earlyExitRange = 0});
    chassis.waitUntilDone();
    pros::delay(150);

}

//Define auton functions.
void _LateralMovementWithSpeed (float XCoord, float YCoord, int Time, bool Forward=true, float maxspeed=127) {

    chassis.moveToPoint(XCoord, YCoord, Time, {.forwards = Forward, .maxSpeed = maxspeed, .minSpeed = 0, .earlyExitRange = 0});
    chassis.waitUntilDone();
    pros::delay(150);

}

void _AngularMovement (float Angle, int Time, bool Direction) {

    AngularDirection augDirection = Direction ? AngularDirection::CW_CLOCKWISE : AngularDirection::CCW_COUNTERCLOCKWISE;    
    chassis.turnToHeading (Angle, Time, {.direction = augDirection, .maxSpeed = 127, .minSpeed = 0, .earlyExitRange = 0});
    chassis.waitUntilDone();
    pros::delay(150);
    
}

void _OuttakeT (int Time) {

    TFlywheel.move(127);
    BFlywheel.move(127);
    pros::delay(Time);
    TFlywheel.brake();
    BFlywheel.brake();

}

void _OuttakeL (int Time) {

    TFlywheel.move(-127);
    BFlywheel.move(-127);
    pros::delay(Time);
    TFlywheel.brake();
    BFlywheel.brake();

}
//Define auton path functions;

void _PathLemT () {
    
    
    chassis.setBrakeMode (pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose (0, 0, 0);

    _LateralMovement (0, 48, 5000, true);
    
   // _AngularMovement (180, 5000, true);
   
}

void _PathLemL () {
    
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(-48, 14, 0, false);

    PneumaticLoad.set_value(true);
    _LateralMovement(-48, 48, 1500, true);
    chassis.setPose(-48, 48, 0, false);
    _AngularMovement(270, 750, false);
    BFlywheel.move(127);
    _LateralMovement(-72, 48, 1500, true);
    pros::delay(1000);
    BFlywheel.brake();
    _LateralMovement(-28, 48, 1500, false);
    chassis.setPose(-30, 48, 270, false);
    _OuttakeT(2000);
    _LateralMovement(-54, 48, 1500, true);
    chassis.setPose(-48, 48, 270, false);   
    _AngularMovement(180, 1000, false);

}

void _PathLemR () {
 
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(-48, -14, 0, false);

    PneumaticLoad.set_value(true);
    _LateralMovement(-48, -48, 1500, true);
    chassis.setPose(-48, -48, 0, false);
    _AngularMovement(270, 750, false);
    BFlywheel.move(127);
    _LateralMovement(-72, -48, 1500, true);
    pros::delay(1000);
    BFlywheel.brake();
    _LateralMovement(-28, -48, 1500, false);
    chassis.setPose(-30, -48, 270, false);
    _OuttakeT(2000);
    _LateralMovement(-54, -48, 1500, true);
    chassis.setPose(-48, -48, 270, false);   
    _AngularMovement(0, 1000, false);

}

void _PathLemN () {

    chassis.setBrakeMode (pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose (-48, 0, 270, false);

    BFlywheel.move(127);
    TFlywheel.move(127);
    _LateralMovement(-36, 0, 1500, false);
    _LateralMovement(-96, 0, 5000, true);
    pros::delay(1000);
    BFlywheel.brake();  
    TFlywheel.brake();

}

void _PathLemS () {

    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(-48, 14, 0, false);

    PneumaticLoad.set_value(true);
    _LateralMovement(-48, 48, 1500, true);
    chassis.setPose(-48, 48, 0, false);
    _AngularMovement(270, 750, false);
    BFlywheel.move(127);
    _LateralMovement(-72, 48, 1500, true);
    pros::delay(1000);
    BFlywheel.brake();
    _LateralMovement(-28, 48, 1500, false);
    chassis.setPose(-30, 48, 270, false);
    _OuttakeT(2000);
    _LateralMovement(-54, 48, 1500, true);
    chassis.setPose(-48, 48, 270, false);   
    _AngularMovement(145, 1000, false);

    PneumaticLoad.set_value(false);
    _LateralMovement (-24, 0, 1500, true);
    _AngularMovement(270, 1000, true);
    BFlywheel.move(127);
    TFlywheel.move(127);
    _LateralMovement(-84, 0, 3000, true);
    pros::delay(1000);
    BFlywheel.brake();
    TFlywheel.brake();

    /*    
    _LateralMovement(-45, -48, 2500, true);
    chassis.setPose(-48, -48, 180, false);
    _AngularMovement(270, 1000, true);
    BFlywheel.move(127);
    _LateralMovement(-72, -48, 1500, true);
    chassis.setPose(-72, -48, 270, false);
    pros::delay(1000);
    BFlywheel.brake();
    _LateralMovement(-30, -48, 1500, false);
    chassis.setPose(-30, -48, 270, false);
    _OuttakeT(2000);
    */

}

void _PathLemA () {

    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(0, 0, 0, false);
    
    _LateralMovement (0, 8, 1000, true);


}


void _PathLemSkills46pts () {
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(-48, 14, 0, false);

    PneumaticLoad.set_value(true);
    int firstMLY = 55;
    int firstMLX = -48;
    _LateralMovement(firstMLX, firstMLY, 1500, true);
    chassis.setPose(firstMLX, firstMLY, 0, false);
    _AngularMovement(270, 750, false);
    
    BFlywheel.move(127);
    _LateralMovement(-72, firstMLY, 1500, true);
    pros::delay(1000);
    BFlywheel.brake();
    _LateralMovement(-24, firstMLY, 2000, false);
    chassis.setPose(-30, firstMLY, 270, false);
    _OuttakeT(3000);
    
    // Now move to the other side to match load from the other
    // side of the field.
    chassis.setPose(-30, firstMLY, 270, false);
    _LateralMovement(-48, firstMLY, 1500, true);
    _AngularMovement(180, 1000, false);

    int secondMLY = -39;
    _LateralMovement(-48, secondMLY, 3000, true);
    chassis.setPose(-48, secondMLY, 180, false);
    _AngularMovement(270, 1000, true);

    // Now pick up the second load and score it.
    BFlywheel.move(127);
    _LateralMovement(-72, secondMLY, 1500, true);
    pros::delay(2000);
    BFlywheel.brake();
    _LateralMovementWithSpeed(-10, secondMLY, 3000, false, 80);
    chassis.setPose(-30, secondMLY, 270, false);
    _OuttakeT(2000);

    /*
    while (true) {
        IMU.get_pitch();
        printf("Pitch: %.2f \n", IMU.get_pitch());
        pros::delay(100);
    }
    */

    // Bring up the match loader and park
    PneumaticLoad.set_value(false);
    chassis.setPose(-30, secondMLY, 270, false);
    _LateralMovement(-48, secondMLY, 1500, true);
    chassis.moveToPose(-70, 0, 0, 1500, {.maxSpeed = 127, .minSpeed = 0, .earlyExitRange = 0});
    _AngularMovement(0, 1000, true);
    BFlywheel.move(127);
    chassis.setPose(-70, 0, 0, false);
    _LateralMovementWithSpeed(-74, 45, 3000, true, 127);
    chassis.setPose(-74, 0, 0, false);
    BFlywheel.brake();
}

void _PathLemSkills() {
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(45, 0, 180);

    // Go to the first match loader and turn towards it
    PneumaticLoad.set_value(true);
    int firstMLY = -40;
    int firstMLX = 45;
    int intakeWaitTime = 3000;
    chassis.moveToPoint(firstMLX, firstMLY, 3000);
    chassis.waitUntilDone();
    chassis.turnToHeading(90, 750, {.maxSpeed = 80});
    chassis.waitUntilDone();
    
    // Intake the blocks from the first match loader
    BFlywheel.move(127);
    chassis.moveToPoint(57, firstMLY, 2800, {.maxSpeed = 50});
    chassis.waitUntilDone();
    BFlywheel.brake();

    // Leave the match loader
    chassis.moveToPoint(48, firstMLY, 3000, {.forwards = false});
    PneumaticLoad.set_value(false);
    chassis.waitUntilDone();

    // Go to the other (blue) side of the field
    chassis.moveToPoint(24, -53, 2000, {.forwards = false});
    chassis.turnToHeading(90, 750);
    chassis.waitUntilDone();
    chassis.moveToPoint(-37, -51, 4000, {.forwards = false});
    chassis.waitUntilDone();

    // Score blocks from the first match loader
    // 1. Turn on the outake
    // 2. Push towards the goal for 1s
    // 3. Stop pushing
    // 4. Continue to outtake for another 3s.
    chassis.moveToPoint(-48, -42, 3000, {.forwards = false});
    chassis.waitUntilDone();
    chassis.turnToHeading(270, 3000);
    chassis.waitUntilDone();
    chassis.moveToPoint(-25, -42, 2250, {.forwards = false, .maxSpeed = 100});
    chassis.waitUntilDone();
    PneuOuttake.set_value(false);
    TFlywheel.move(127);
    BFlywheel.move(127);
    chassis.arcade(-100, 0);
    pros::delay(1000);
    chassis.arcade(0, 0);
    pros::delay(3000);
    TFlywheel.brake();
    BFlywheel.brake();
    chassis.turnToHeading(270, 1000);
    chassis.setPose(-22, -39, 270);

    // Intake the second match loader
    PneumaticLoad.set_value(true);
    BFlywheel.move(127);
    chassis.moveToPoint(-86, -37, 3000, {.maxSpeed = 55});
    chassis.waitUntilDone();
    BFlywheel.brake();

    // Score blocks from the second match loader
    // 1. Turn on the outake
    // 2. Push towards the goal for 1s
    // 3. Stop pushing
    // 4. Continue to outtake for another 3s.
    chassis.moveToPoint(-26, -39, 2500, {.forwards = false, .maxSpeed = 100});
    chassis.waitUntilDone();
    TFlywheel.move(127);
    BFlywheel.move(127);
    chassis.arcade(-80, 0);
    pros::delay(1000);
    chassis.arcade(0, 0);
    pros::delay(3000);
    TFlywheel.brake();
    BFlywheel.brake();
    chassis.turnToHeading(270, 1000);
    chassis.setPose(-30, -46, 270);

    // Go to the right side of the field
    chassis.moveToPoint(-45, -46, 3000);
    chassis.waitUntilDone();
    chassis.turnToHeading(0, 2000);
    chassis.waitUntilDone();
    chassis.moveToPoint(-45, 41, 4000, {.maxSpeed = 127}); // Big straight to other side
    chassis.waitUntilDone();
    chassis.turnToHeading(-90, 1000, {}, false);
    chassis.waitUntilDone();

    // Intake blocks from the third match loader
    BFlywheel.move(127);
    chassis.moveToPoint(-70, 43, 3000, {.maxSpeed = 55});
    chassis.waitUntilDone();
    BFlywheel.brake();
    chassis.setPose(-57, 43, 270);

    // Leave the match loader
    chassis.moveToPoint(-52, 42, 3000, {.forwards = false});
    chassis.waitUntilDone();
    PneumaticLoad.set_value(false);

    // Go to the other(red) side of the field
    chassis.moveToPoint(-26, 65, 3000, {.forwards = false});
    chassis.waitUntilDone();
    chassis.turnToHeading(270, 750);
    chassis.waitUntilDone();
    chassis.moveToPoint(41, 68, 4000, {.forwards = false});
    chassis.waitUntilDone();

    // Score blocks from the third match loader
    chassis.moveToPoint(53, 52, 3000, {.forwards = false});
    chassis.waitUntilDone();
    chassis.turnToHeading(90, 3000);
    chassis.waitUntilDone();
    chassis.moveToPoint(21, 52, 2500, {.forwards = false, .maxSpeed = 100});
    chassis.waitUntilDone();
    PneuOuttake.set_value(false);
    TFlywheel.move(127);
    BFlywheel.move(127);
    chassis.arcade(-80, 0);
    pros::delay(1000);
    chassis.arcade(0, 0);
    pros::delay(3000);
    TFlywheel.brake();
    BFlywheel.brake();

    // Park
    PneumaticLoad.set_value(false);
    chassis.turnToHeading(270, 1000);
    chassis.setPose(-30, -39, 270, false);
    chassis.moveToPoint(-48, -39, 1500);
    chassis.waitUntilDone();
    chassis.moveToPose(-70, 0, 0, 1500, {.maxSpeed = 127, .minSpeed = 0, .earlyExitRange = 0});
    chassis.waitUntilDone();
    chassis.turnToHeading(0, 1000, {.direction = AngularDirection::CW_CLOCKWISE});
    chassis.waitUntilDone();
    BFlywheel.move(127);
    chassis.setPose(-70, 0, 0, false);
    chassis.moveToPoint(-77, 45, 3000, {.maxSpeed = 127});
    chassis.waitUntilDone();
    BFlywheel.brake();
}


void _PathLemSkillsWithFourthMatchLoader() {
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(45, 0, 180);
    
    // Go to the first match loader and turn towards it
    PneumaticLoad.set_value(true);
    int firstMLY = -40;
    int firstMLX = 45;
    int intakeWaitTime = 3000;
    chassis.moveToPoint(firstMLX, firstMLY, 3000);
    chassis.waitUntilDone();
    chassis.turnToHeading(90, 750, {.maxSpeed = 80});
    chassis.waitUntilDone();
    
    // Intake the blocks from the first match loader
    BFlywheel.move(127);
    chassis.moveToPoint(57, firstMLY, 2800, {.maxSpeed = 50});
    chassis.waitUntilDone();
    BFlywheel.brake();

    // Leave the match loader
    chassis.moveToPoint(48, firstMLY, 3000, {.forwards = false});
    PneumaticLoad.set_value(false);
    chassis.waitUntilDone();

    // Go to the other (blue) side of the field
    chassis.moveToPoint(24, -53, 2000, {.forwards = false});
    chassis.turnToHeading(90, 750);
    chassis.waitUntilDone();
    chassis.moveToPoint(-37, -51, 4000, {.forwards = false});
    chassis.waitUntilDone();

    // Score blocks from the first match loader
    // 1. Turn on the outake
    // 2. Push towards the goal for 1s
    // 3. Stop pushing
    // 4. Continue to outtake for another 3s.
    chassis.moveToPoint(-48, -43, 3000, {.forwards = false});
    chassis.waitUntilDone();
    chassis.turnToHeading(270, 3000);
    chassis.waitUntilDone();
    chassis.moveToPoint(-25, -43, 2250, {.forwards = false, .maxSpeed = 100});
    chassis.waitUntilDone();
    PneuOuttake.set_value(false);
    TFlywheel.move(127);
    BFlywheel.move(127);
    chassis.arcade(-100, 0);
    pros::delay(1500);
    chassis.arcade(0, 0);
    pros::delay(1500);
    TFlywheel.brake();
    BFlywheel.brake();
    chassis.turnToHeading(270, 1000);
    chassis.setPose(-22, -39, 270);

    // Intake the second match loader
    PneumaticLoad.set_value(true);
    BFlywheel.move(127);
    chassis.moveToPoint(-86, -37, 3000, {.maxSpeed = 55});
    chassis.waitUntilDone();
    BFlywheel.brake();

    // Score blocks from the second match loader
    // 1. Turn on the outake
    // 2. Push towards the goal for 1s
    // 3. Stop pushing
    // 4. Continue to outtake for another 3s.
    chassis.moveToPoint(-26, -39, 2500, {.forwards = false, .maxSpeed = 100});
    chassis.waitUntilDone();
    TFlywheel.move(127);
    BFlywheel.move(127);
    chassis.arcade(-80, 0);
    pros::delay(1000);
    chassis.arcade(0, 0);
    pros::delay(3000);
    TFlywheel.brake();
    BFlywheel.brake();
    chassis.turnToHeading(270, 1000);
    
    chassis.setPose(-30, -46, 270);
    PneumaticLoad.set_value(true);

    // Go to the right side of the field
    chassis.moveToPoint(-45, -46, 3000);
    chassis.waitUntilDone();
    chassis.turnToHeading(0, 2000);
    chassis.waitUntilDone();
    chassis.moveToPoint(-45, 41.5, 4000, {.maxSpeed = 127}); // Big straight to other side
    chassis.waitUntilDone();
    chassis.turnToHeading(270, 1000, {}, false);
    chassis.waitUntilDone();

    // Intake blocks from the third match loader
    BFlywheel.move(127);
    chassis.moveToPoint(-70, 41.5, 3000, {.maxSpeed = 55});
    chassis.waitUntilDone();
    BFlywheel.brake();
    chassis.setPose(-57, 41.5, 270);

    // Leave the match loader
    chassis.moveToPoint(-52, 41.5, 3000, {.forwards = false});
    chassis.waitUntilDone();
    PneumaticLoad.set_value(false);
    
    // Go to the other(red) side of the field
    chassis.moveToPoint(-26, 62, 3000, {.forwards = false});
    chassis.waitUntilDone();
    chassis.turnToHeading(270, 750);
    chassis.waitUntilDone();
    chassis.moveToPoint(32, 64, 4000, {.forwards = false});
    chassis.waitUntilDone();
    
    // Score blocks from the third match loader
    chassis.moveToPoint(45, 52, 3000, {.forwards = false});
    chassis.waitUntilDone();
    chassis.turnToHeading(90, 3000);
    chassis.waitUntilDone();
    chassis.moveToPoint(21, 52, 2500, {.forwards = false, .maxSpeed = 100});
    chassis.waitUntilDone();
    PneuOuttake.set_value(false);
    TFlywheel.move(127);
    BFlywheel.move(127);
    chassis.arcade(-80, 0);
    pros::delay(1000);
    chassis.arcade(0, 0);
    pros::delay(2000);
    TFlywheel.brake();
    BFlywheel.brake();
    chassis.setPose(21, 52, 90);

    
    // Now pick up the fourth match loader
    PneumaticLoad.set_value(true);
    BFlywheel.move(127);
    chassis.moveToPoint(48, 52, 4000, {.maxSpeed = 127});
    chassis.moveToPoint(52, 52, 2000, {.maxSpeed = 60});
    chassis.waitUntilDone();
    BFlywheel.brake();

    // Score blocks from the fourth match loader
    chassis.moveToPoint(21, 52, 3000, {.forwards = false, .maxSpeed = 100});
    chassis.waitUntilDone();
    PneuOuttake.set_value(false);
    TFlywheel.move(127);
    BFlywheel.move(127);
    chassis.arcade(-100, 0);
    pros::delay(500);
    chassis.arcade(0, 0);
    pros::delay(1500);
    TFlywheel.brake();
    BFlywheel.brake();

    // Park
    PneumaticLoad.set_value(false);
    chassis.turnToHeading(270, 1000);
    chassis.setPose(-30, -39, 270, false);
    chassis.moveToPoint(-48, -39, 1500);
    chassis.waitUntilDone();
    chassis.moveToPose(-70, 0, 0, 1500, {.maxSpeed = 127, .minSpeed = 0, .earlyExitRange = 0});
    chassis.waitUntilDone();
    chassis.turnToHeading(0, 1000, {.direction = AngularDirection::CW_CLOCKWISE});
    chassis.waitUntilDone();
    BFlywheel.move(127);
    chassis.setPose(-70, 0, 0, false);
    chassis.moveToPoint(-77, 45, 3000, {.maxSpeed = 127});
    chassis.waitUntilDone();
    BFlywheel.brake();
}


void _PathLemSkillsNewField() {
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(45, 0, 180);
    
    // Go to the first match loade  r and turn towards it
    PneumaticLoad.set_value(true);
    int firstMLY = -40;
    int firstMLX = 45;
    int intakeWaitTime = 3000;
    chassis.moveToPoint(firstMLX, firstMLY, 3000);
    chassis.waitUntilDone();
    chassis.turnToHeading(90, 750, {.maxSpeed = 80});
    chassis.waitUntilDone();
    
    // Intake the blocks from the first match loader
    BFlywheel.move(127);
    chassis.moveToPoint(57, firstMLY, 2800, {.maxSpeed = 50});
    chassis.waitUntilDone();
    BFlywheel.brake();

    // Leave the match loader
    chassis.moveToPoint(48, firstMLY, 3000, {.forwards = false});
    PneumaticLoad.set_value(false);
    chassis.waitUntilDone();

    // Go to the other (blue) side of the field
    chassis.moveToPoint(24, -52, 2000, {.forwards = false});
    chassis.turnToHeading(90, 750);
    chassis.waitUntilDone();
    chassis.moveToPoint(-37, -50, 4000, {.forwards = false});
    chassis.waitUntilDone();

    // Score blocks from the first match loader
    // 1. Turn on the outake
    // 2. Push towards the goal for 1s
    // 3. Stop pushing
    // 4. Continue to outtake for another 3s.
    chassis.moveToPoint(-48, -43, 3000, {.forwards = false});
    chassis.waitUntilDone();
    chassis.turnToHeading(270, 3000);
    chassis.waitUntilDone();
    chassis.moveToPoint(-25, -43, 2250, {.forwards = false, .maxSpeed = 100});
    chassis.waitUntilDone();
    PneuOuttake.set_value(false);
    TFlywheel.move(127);
    BFlywheel.move(127);
    chassis.arcade(-100, 0);
    pros::delay(1500);
    chassis.arcade(0, 0);
    pros::delay(1500);
    TFlywheel.brake();
    BFlywheel.brake();
    chassis.turnToHeading(270, 1000);
    chassis.setPose(-22, -39, 270);

    // Intake the second match loader
    PneumaticLoad.set_value(true);
    BFlywheel.move(127);
    chassis.moveToPoint(-86, -37, 3000, {.maxSpeed = 55});
    chassis.waitUntilDone();
    BFlywheel.brake();

    // Score blocks from the second match loader
    // 1. Turn on the outake
    // 2. Push towards the goal for 1s
    // 3. Stop pushing
    // 4. Continue to outtake for another 3s.
    chassis.moveToPoint(-26, -39, 2500, {.forwards = false, .maxSpeed = 100});
    chassis.waitUntilDone();
    TFlywheel.move(127);
    BFlywheel.move(127);
    chassis.arcade(-80, 0);
    pros::delay(1000);
    chassis.arcade(0, 0);
    pros::delay(3000);
    TFlywheel.brake();
    BFlywheel.brake();
    chassis.turnToHeading(270, 1000);
    
    chassis.setPose(-30, -46, 270);
    PneumaticLoad.set_value(true);

    // Go to the right side of the field
    chassis.moveToPoint(-45, -46, 3000);
    chassis.waitUntilDone();
    chassis.turnToHeading(0, 2000);
    chassis.waitUntilDone();
    chassis.moveToPoint(-45, 41.5, 4000, {.maxSpeed = 127}); // Big straight to other side
    chassis.waitUntilDone();
    chassis.turnToHeading(270, 1000, {}, false);
    chassis.waitUntilDone();

    // Intake blocks from the third match loader
    BFlywheel.move(127);
    chassis.moveToPoint(-70, 41.5, 3000, {.maxSpeed = 55});
    chassis.waitUntilDone();
    BFlywheel.brake();
    chassis.setPose(-57, 41.5, 270);

    // Leave the match loader
    chassis.moveToPoint(-52, 41.5, 3000, {.forwards = false});
    chassis.waitUntilDone();
    PneumaticLoad.set_value(false);
    
    // Go to the other(red) side of the field
    chassis.moveToPoint(-26, 62, 3000, {.forwards = false});
    chassis.waitUntilDone();
    chassis.turnToHeading(270, 750);
    chassis.waitUntilDone();
    chassis.moveToPoint(32, 64, 4000, {.forwards = false});
    chassis.waitUntilDone();
    
    // Score blocks from the third match loader
    chassis.moveToPoint(45, 52, 3000, {.forwards = false});
    chassis.waitUntilDone();
    chassis.turnToHeading(90, 3000);
    chassis.waitUntilDone();
    chassis.moveToPoint(21, 52, 2500, {.forwards = false, .maxSpeed = 100});
    chassis.waitUntilDone();
    PneuOuttake.set_value(false);
    TFlywheel.move(127);
    BFlywheel.move(127);
    chassis.arcade(-80, 0);
    pros::delay(1000);
    chassis.arcade(0, 0);
    pros::delay(2000);
    TFlywheel.brake();
    BFlywheel.brake();
    chassis.setPose(21, 52, 90);

    
    // Now pick up the fourth match loader
    PneumaticLoad.set_value(true);
    BFlywheel.move(127);
    chassis.moveToPoint(48, 52, 4000, {.maxSpeed = 127});
    chassis.moveToPoint(52, 52, 2000, {.maxSpeed = 60});
    chassis.waitUntilDone();
    BFlywheel.brake();

    // Score blocks from the fourth match loader
    chassis.moveToPoint(21, 52, 3000, {.forwards = false, .maxSpeed = 100});
    chassis.waitUntilDone();
    PneuOuttake.set_value(false);
    TFlywheel.move(127);
    BFlywheel.move(127);
    chassis.arcade(-100, 0);
    pros::delay(500);
    chassis.arcade(0, 0);
    pros::delay(1500);
    TFlywheel.brake();
    BFlywheel.brake();

    // Park
    PneumaticLoad.set_value(false);
    chassis.turnToHeading(270, 1000);
    chassis.setPose(-30, -39, 270, false);
    chassis.moveToPoint(-48, -39, 1500);
    chassis.waitUntilDone();
    chassis.moveToPose(-70, 0, 0, 1500, {.maxSpeed = 127, .minSpeed = 0, .earlyExitRange = 0});
    chassis.waitUntilDone();
    chassis.turnToHeading(0, 1000, {.direction = AngularDirection::CW_CLOCKWISE});
    chassis.waitUntilDone();
    BFlywheel.move(127);
    chassis.setPose(-70, 0, 0, false);
    chassis.moveToPoint(-77, 45, 3000, {.maxSpeed = 127});
    chassis.waitUntilDone();
    BFlywheel.brake();
}


void _MovementWithDistanceSensor() {
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(-50, 0, 180);
    int _distFromWall = 580;

    chassis.moveToPoint(-50, -40, 5000);
    chassis.waitUntilDone();

    int distance = frontDistanceSensor.get();
    int actualY = _distFromWall - distance;

    chassis.turnToHeading(90, 5000);
    chassis.waitUntilDone();
    chassis.setPose(-50, -actualY, 90);
    printf("Distance: %d, Actual Y: %d \n", distance, actualY);
    chassis.moveToPoint(70, -30, 5000);
    chassis.waitUntilDone();
}