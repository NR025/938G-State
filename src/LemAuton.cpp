/**
 * 2026 Pushback Tournament
 * Team 938G Coder ARM
 * Pros ProsAuton.cpp
 */

//Include initialized devices and ProsAuton.h.
#include "Lem_Initialize.h"
#include "LemAuton.h"
#include "lemlib/timer.hpp"

//#Define auton utility variables.

float getDistanceInInches(pros::Distance& sensor) {
    return sensor.get() * 0.0393701;
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

void outtake() {
    // Start a 2s timer.
    lemlib::Timer loadTimer(2500);
    TFlywheel.move(127);
    BFlywheel.move(127);
    chassis.arcade(60, 0);

    // 276 is the distance in mm that the sensor reads when there are no blocks
    // 100 is a distance threshold that was determined through testing.
    int blockdistance = 110;
    int numBlocks = 0;
    int state = 0; // 0 = no blocks, 1 = one block
    while (numBlocks < 6 && !loadTimer.isDone()) {
        int intakeDistance = outtakeDistanceSensor.get();

        pros::lcd::print(1, "Blocks: %d Time: %d\n", numBlocks, loadTimer.getTimeLeft()); 
        if (intakeDistance <= blockdistance && state == 0) {
            // Flip the state to one so we dont count
            // the same block multiple times.
            state = 1;
            numBlocks++;
        } else if (intakeDistance > blockdistance && state == 1) {
            // Flip the state back to zero so the next block
            // can be detected.
            state = 0;
        } 

        pros::delay(10);
    }
    
    // Run the outtake for a bit longer to ensure we
    // got all the blocks.
    pros::delay(200);
    TFlywheel.brake();
    BFlywheel.brake();
    chassis.arcade(0, 0);
}

// This function runs the intake till all the blocks are loaded.
// The idea is to use timing and the distancec sensor to determine when the
// blocks are loaded.
void matchLoad() {
    // Intake the blocks from the first match loader
    PneumaticLoad.set_value(true);
    
    // Start a 2s timer.
    lemlib::Timer loadTimer(2500);
    BFlywheel.move(127);
    chassis.arcade(60, 0);

    // 276 is the distance in mm that the sensor reads when there are no blocks
    // 100 is a distance threshold that was determined through testing.
    int blockdistance = 110;
    int numBlocks = 0;
    int state = 0; // 0 = no blocks, 1 = one block
    while (numBlocks < 6 && !loadTimer.isDone()) {
        int intakeDistance = intakeDistanceSensor.get();

        pros::lcd::print(1, "Blocks: %d Time: %d\n", numBlocks, loadTimer.getTimeLeft()); 
        if (intakeDistance <= blockdistance && state == 0) {
            // Flip the state to one so we dont count
            // the same block multiple times.
            state = 1;
            numBlocks++;
        } else if (intakeDistance > blockdistance && state == 1) {
            // Flip the state back to zero so the next block
            // can be detected.
            state = 0;
        } 

        pros::delay(20);
    }
    
    // Run the intake for a bit longer to ensure we
    // got all the blocks.
    pros::delay(500);
    BFlywheel.brake();
    chassis.arcade(0, 0);
}

void getToFirstMatchLoader() {
    float halfFieldDistance = 72;
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(49, -8, 180);
    PneumaticLoad.set_value(true);
 
    chassis.moveToPoint(49, -51, 5000);
    chassis.waitUntilDone();

    // Calculate the actual robot position and ensure we drove the right 
    // distance in case we are off using the front distance sensor.
    float currentRobotDistanceFromWall = getDistanceInInches(frontDistanceSensor) + FRONT_DISTANCE_SENSOR_TO_CENTER;
    float currentRobotDistanceFromStart = halfFieldDistance - currentRobotDistanceFromWall;
    float currentY = currentRobotDistanceFromStart;
    chassis.setPose(49, -1 * currentY, 180);
    chassis.moveToPoint(49, -51, 2000);
   
    // Now turn towards the match loader.
    chassis.turnToHeading(90, 2000, {.maxSpeed = 100});
    chassis.waitUntilDone();
    
    /*
    float distanceFromLoaderWall = getDistanceInInches(leftDistanceSensor)  + LEFT_DISTANCE_SENSOR_TO_CENTER;
    currentY = halfFieldDistance - distanceFromLoaderWall;
    */
    
    /*
    pros::lcd::print(1, "X %f\n", currentX); // -328, 53
    pros::lcd::print(2, "Y %f\n", currentY); 
    pros::delay(5000);
    */
    
    // Drive torwards the match loader and intake.
    chassis.moveToPoint(57, -51, 1000);
    chassis.waitUntilDone();
    chassis.turnToHeading(90, 500);
    chassis.waitUntilDone();
    
    // Set the pose 
    chassis.setPose(58, -48, 90);
}

void getToFirstDropOff() {
    chassis.moveToPoint(54, -48, 2000, {.forwards = false});
    PneumaticLoad.set_value(false);
    chassis.waitUntilDone();

    // Go to the other (blue) side of the field
    chassis.moveToPoint(40, -60, 2000, {.forwards = false});
    chassis.turnToHeading(90, 750);
    chassis.waitUntilDone();
    chassis.moveToPoint(-35, -60, 4000, {.forwards = false});
    chassis.waitUntilDone();

    // Measure the distance of the left color distance from the wall.
    float currentRobotDistanceFromWall = getDistanceInInches(rightDistanceSensor) + RIGHT_DISTANCE_SENSOR_TO_CENTER;
    float currentRobotDistanceFromStart = HALF_FIELD_DISTANCE - currentRobotDistanceFromWall;
    float currentY = currentRobotDistanceFromStart;
    chassis.setPose(-35, -1 * currentY, 90);
    pros::lcd::print(1, "Y: %f\n", currentY); // -328, 53
    pros::delay(5000);

    /*
    // Align with the other side of the field.
    chassis.moveToPoint(-48, -43, 3000, {.forwards = false});
    chassis.waitUntilDone();
    chassis.turnToHeading(270, 3000);
    
    chassis.waitUntilDone();
    chassis.moveToPoint(-25, -43, 2250, {.forwards = false, .maxSpeed = 100});
    chassis.waitUntilDone();
    */
}

void _MovementWithDistanceSensor() {
    getToFirstMatchLoader();
    matchLoad();
    getToFirstDropOff();
}