/**
 * 2026 Pushback Tournament
 * Team 938G Coder ARM
 * Pros ProsAuton.cpp
 */

 /*
 * This is the co-ordinate plane below, the points are in (x,y)
 * This looking at the field with the Red on the right side
 * and blue on the left side when looking from outside onto the field.
 *   
 *
 *               (-, +)  |  (+, +)
 *  blue park    _________________   red park
 *               (-, -)  |  (+, -)
 *
 *
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

float calculateDistanceFromFront() {
    // Calculate the actual robot position and ensure we drove the right 
    // distance in case we are off using the front distance sensor.
    float currentRobotDistanceFromWall = getDistanceInInches(frontDistanceSensor) + FRONT_DISTANCE_SENSOR_TO_CENTER;
    float currentRobotDistanceFromStart = HALF_FIELD_DISTANCE - currentRobotDistanceFromWall;
    return currentRobotDistanceFromStart;
}

float calculateDistanceFromLeft() {
    // Calculate the actual robot position and ensure we drove the right 
    // distance in case we are off using the front distance sensor.
    float currentRobotDistanceFromWall = getDistanceInInches(leftDistanceSensor) + LEFT_DISTANCE_SENSOR_TO_CENTER;
    float currentRobotDistanceFromStart = HALF_FIELD_DISTANCE - currentRobotDistanceFromWall;
    return currentRobotDistanceFromStart;
}

float calculateDistanceFromRight() {
    // Calculate the actual robot position and ensure we drove the right 
    // distance in case we are off using the front distance sensor.
    float currentRobotDistanceFromWall = getDistanceInInches(rightDistanceSensor) + RIGHT_DISTANCE_SENSOR_TO_CENTER;
    float currentRobotDistanceFromStart = HALF_FIELD_DISTANCE - currentRobotDistanceFromWall;
    return currentRobotDistanceFromStart;
}

float calculateDistanceFromBack() {
    // Calculate the actual robot position and ensure we drove the right 
    // distance in case we are off using the front distance sensor.
    float currentRobotDistanceFromWall = getDistanceInInches(backDistanceSensor) + BACK_DISTANCE_SENSOR_TO_CENTER;
    float currentRobotDistanceFromStart = HALF_FIELD_DISTANCE - currentRobotDistanceFromWall;
    return currentRobotDistanceFromStart;
}

void outtake(int arcadeTime) {
    TFlywheel.move(127);
    BFlywheel.move(127);
    chassis.arcade(-60, 0);

    // Start a 5s timer.
    int totalTime = 3000;
    int arcadeCheckTime = totalTime - arcadeTime;
    if (arcadeCheckTime < 0) {
        arcadeCheckTime = 0;
    }

    lemlib::Timer loadTimer(totalTime);
    
    // 276 is the distance in mm that the sensor reads when there are no blocks
    // 100 is a distance threshold that was determined through testing. 
    int blockdistance = 110;
    int numBlocks = 0;
    int state = 0; // 0 = no blocks, 1 = one block
    while (numBlocks < 6 && !loadTimer.isDone()) {

        // Only push back into the goal for a second and half, do not push back more.
        // When we push more, the battery power is distributed and 
        // the outtake does not work as well.
        if (loadTimer.getTimeLeft() <= arcadeCheckTime) {
            chassis.arcade(0, 0);
        }

        int intakeDistance = outtakeDistanceSensor.get();

        //pros::lcd::print(1, "Blocks: %d Time: %d\n", numBlocks, loadTimer.getTimeLeft()); 
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
    loadTimer.pause();

    // We can add more intelligence here, if the number of 
    // balls are lower than 6, then we could try to unjam the outtake.
    // we run it backward and then try to outtake again.
    // For now we dont do this, because if the block detection is
    // Broken then we will be in a bad situation where we keep running the outtake forever.

    // Run the outtake for a bit longer to ensure we
    // got all the blocks.
    chassis.arcade(0, 0);
    pros::delay(800);
    TFlywheel.brake();
    BFlywheel.brake();
}

// This function runs the intake till all the blocks are loaded.
// The idea is to use timing and the distancec sensor to determine when the
// blocks are loaded.
void matchLoad(int arcadeSpeed, int time) {
    // Intake the blocks from the first match loader
    PneumaticLoad.set_value(true);
    
    //Start the flywheels and start driving forward.
    BFlywheel.move(127);
    chassis.arcade(arcadeSpeed, 0);

    // Start a 2s timer.
    lemlib::Timer loadTimer(time);

    // 276 is the distance in mm that the sensor reads when there are no blocks
    // 100 is a distance threshold that was determined through testing.
    int blockdistance = 110;
    int numBlocks = 0;
    int state = 0; // 0 = no blocks, 1 = one block
    while (numBlocks < 6 && !loadTimer.isDone()) {
        int intakeDistance = intakeDistanceSensor.get();

        // Only push back into the goal for a second, do not push back more.
        // When we push more, the battery power is distributed and 
        // the outtake does not work as well.
        if (loadTimer.getTimeLeft() < 1500) {
            chassis.arcade(0, 0);
        }

        //pros::lcd::print(1, "Blocks: %d TLeft: %d TPassed: %d\n", numBlocks, loadTimer.getTimeLeft(), loadTimer.getTimePassed()); 
        if (intakeDistance <= blockdistance && state == 0) {
            // Flip the state to one so we dont count
            // the same block multiple times.s
            state = 1;
            numBlocks++;
        } else if (intakeDistance > blockdistance && state == 1) {
            // Flip the state back to zero so the next block
            // can be detected.
            state = 0;
        } 

        pros::delay(20);
    }
    
    loadTimer.pause();

    // Run the intake for a bit longer to ensure we
    // got all the blocks.
    pros::delay(800);
    BFlywheel.brake();
    chassis.arcade(0, 0);
}

void getToFirstMatchLoader() {
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(49, -8, 180);
    PneumaticLoad.set_value(true);
 
    chassis.moveToPoint(49, -51, 5000);
    chassis.waitUntilDone();

    // Calculate the actual robot position and ensure we drove the right 
    // distance in case we are off using the front distance sensor.
    float currentY = calculateDistanceFromFront();
    chassis.setPose(49, -1 * currentY, 180);
    chassis.moveToPose(49, -51, 180, 2000, {.maxSpeed = 100});
    chassis.waitUntilDone();
   
    // Now turn towards the match loader.
    chassis.turnToHeading(90, 2000);
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
    chassis.moveToPoint(55, -51, 2000);
    chassis.waitUntilDone();
}

void getToFirstDropOff() {
    chassis.moveToPoint(50, -51, 2000, {.forwards = false});
    chassis.waitUntilDone();

    PneumaticLoad.set_value(false);

    // Go to the other (blue) side of the field
    chassis.moveToPoint(40, -61, 2000, {.forwards = false});
    chassis.waitUntilDone();
    chassis.turnToHeading(90, 750);
    chassis.waitUntilDone();

    // This is the long straight. Broken into two to make
    // sure we dont hit the goal.
    chassis.moveToPoint(-10, -61, 4000, {.forwards = false}); 
    chassis.waitUntilDone();
    float currentY = calculateDistanceFromRight();
    chassis.setPose(-10, -1 * currentY, chassis.getPose().theta);
    // Finish the long straight.
    chassis.moveToPoint(-30, -61, 4000, {.forwards = false}); 
    chassis.waitUntilDone();


    // Measure the distance of the left color distance from the wall.
    float currentX = calculateDistanceFromBack();
    currentY = calculateDistanceFromRight();
    chassis.setPose(-1 * currentX, -1 * currentY, chassis.getPose().theta);
    //pros::lcd::print(1, "X: %f\n", currentX); 
    //pros::lcd::print(2, "Y: %f\n", currentY); 
    
    // Align with the other side of the field.
    chassis.moveToPoint(-40, -46, 3000, {.forwards = false});
    chassis.waitUntilDone();
    chassis.turnToHeading(270, 3000);
    chassis.waitUntilDone();

    // The X should be -31 however it needs to be 
    // -23 for some reason.
    chassis.moveToPoint(-23, -48, 2250, {.forwards = false, .maxSpeed = 80});
    chassis.waitUntilDone();
}

void getToFirstDropOffMotionChained() {
    chassis.moveToPoint(50, -51, 2000, {.forwards = false, .minSpeed = 100});

    // Wait for movement until 3 inches before bringing
    // the intake up.
    chassis.waitUntil(3);
    PneumaticLoad.set_value(false);
    
    // Go to the other (blue) side of the field
    chassis.moveToPoint(35, -63, 2000, {.forwards = false, .minSpeed = 100});
    chassis.turnToHeading(90, 750, {.maxSpeed = 80, .minSpeed = 80});

    // This is the long straight.
    // We continuously measure the distance from the wall. 
    // If the robot gets too close to the goal, or too far from the wall.
    // then we break and reset.
    chassis.moveToPoint(-40, -63, 4000, {.forwards = false, .minSpeed = 40}); 
    while (true) {
        if (chassis.getPose().x <= -40) {
            break;
        }
        float currentY = calculateDistanceFromRight();
        if (currentY < 59) {
            // We got too close to the goal.
            // Reset the drivetrain location and continue.
            chassis.cancelAllMotions();
            float currentX = calculateDistanceFromBack();
            chassis.setPose(-1 * currentX, -1 * currentY, chassis.getPose().theta);
            chassis.moveToPoint(-40, -63, 4000, {.forwards = false, .maxSpeed = 80, .minSpeed = 40}); 
        }
        pros::delay(10); 
    }

    // Now swing and get to align with the goal and wait for this action to finish.
    chassis.moveToPose(-40, -46, 270, 3000, {.forwards = false});
    chassis.waitUntilDone();

    // Now measure where we are.
    float currentX = calculateDistanceFromFront();
    float currentY = calculateDistanceFromLeft();
    chassis.setPose(-1 * currentX, -1 * currentY, chassis.getPose().theta);
    //pros::lcd::print(1, "X: %f\n", currentX); 
    //pros::lcd::print(2, "Y: %f\n", currentY); 
    
    // Now align with the goal.
    // The X should be -31 however it needs to be 
    // -23 for some reason. We backup till the back
    // distance sensor shows us that we are close to the goal.
    chassis.moveToPoint(-23, -48, 2250, {.forwards = false, .maxSpeed = 80});
    chassis.waitUntilDone();
}

void getToSecondMatchLoader() {
    PneumaticLoad.set_value(true);
    chassis.moveToPoint(-55, -48, 2000);
	chassis.waitUntilDone();
}

void getToSecondDropOff() {
    PneumaticLoad.set_value(false);
    chassis.moveToPoint(-31, -48, 2250, {.forwards = false});
    chassis.waitUntilDone();
}

void getToThirdMatchLoader() {
    chassis.moveToPoint(-48, -48, 2000);
    chassis.waitUntilDone();

    chassis.turnToHeading(0, 1000);
    chassis.waitUntilDone();

    // We want to get to (-48, 49) however we drive a little less intentionally
    // and let the distance sensor fix us.
    chassis.moveToPoint(-48, 40, 4000);
    chassis.waitUntilDone();

    // Calculate the actual robot position and ensure we drove the right 
    // distance in case we are off using the front distance sensor.
    float currentY = calculateDistanceFromFront();
    chassis.setPose(-48, currentY, 0);
    chassis.moveToPose(-48, 49, 0, 2000, {.maxSpeed = 80});
    chassis.waitUntilDone();

    // Turn towards the match loader.
    chassis.turnToHeading(270, 1000);
    chassis.waitUntilDone();

    // Bring down the loader and drive towards the loader.
    PneumaticLoad.set_value(true);
    chassis.moveToPoint(-55, 49, 4000, {.maxSpeed = 80});
    chassis.waitUntilDone();
}

void getToThirdMatchLoaderMotionChained() {
    chassis.moveToPoint(-48, -48, 2000, {.minSpeed = 100});
    chassis.turnToHeading(0, 1000, {.minSpeed = 100});
    
    // We want to get to (-48, 49) however we drive a little less intentionally
    // and let the distance sensor fix us.
    chassis.moveToPoint(-48, 40, 4000, {.minSpeed = 100});
    chassis.waitUntilDone();

    // Calculate the actual robot position and ensure we drove the right 
    // distance in case we are off using the front distance sensor.
    float currentY = calculateDistanceFromFront();
    chassis.setPose(-48, currentY, 0);
    chassis.moveToPose(-48, 49, 0, 2000, {.maxSpeed = 80});
    chassis.waitUntilDone();

    // Turn towards the match loader.
    chassis.turnToHeading(270, 1000);
    chassis.waitUntilDone();

    // Bring down the loader and drive towards the loader.
    PneumaticLoad.set_value(true);
    chassis.moveToPoint(-55, 49, 4000, {.maxSpeed = 80});
    chassis.waitUntilDone();
}

void getToThirdDropOff() {
    //pros::delay(10000);
    chassis.moveToPoint(-50, 49, 2000, {.forwards = false});
    chassis.waitUntilDone();

    // Measure the distance of the left color distance from the wall.
    float currentY = calculateDistanceFromRight();
    chassis.setPose(-50, currentY, chassis.getPose().theta);
    //pros::lcd::print(2, "Y: %f\n", currentY); 
    PneumaticLoad.set_value(false);
    
    // Go to the other (blue) side of the field
    chassis.moveToPoint(-35, 61, 2000, {.forwards = false});
    chassis.waitUntilDone();
    chassis.turnToHeading(270, 750);
    chassis.waitUntilDone();

    // BIG STRAIGHT STARTS HERE. Its broken into two parts
    // We want to make sure we dont hit the goal when we do the straight.
    chassis.moveToPoint(10, 61, 4000, {.forwards = false}); // Big straight to other side
    chassis.waitUntilDone();

    // Measure how far we are from the wall so can correct
    currentY = calculateDistanceFromRight();
    chassis.setPose(10, currentY, chassis.getPose().theta);
    //pros::lcd::print(1, "Y: %f\n", currentY); 
    PneumaticLoad.set_value(false);

    // Finish the long straight
    chassis.moveToPoint(30, 61, 2000, {.forwards = false});
    chassis.waitUntilDone();

    chassis.turnToHeading(270, 2000);
    chassis.waitUntilDone();

    // Measure the distance of the right distance from the wall.
    float currentX = calculateDistanceFromBack();
    currentY = calculateDistanceFromRight();
    
    chassis.setPose(currentX, currentY, 270);
    //pros::lcd::print(1, "X: %f\n", currentX); 
    //pros::lcd::print(2, "Y: %f\n", currentY); 
    
    // Align with the other side of the field.
    // Note that we go to 46 and then turn and that
    // line is considered 47 inches.
    chassis.moveToPoint(40, 46, 2000, {.forwards = false});
    chassis.waitUntilDone();
    chassis.turnToHeading(90, 1000);
    chassis.waitUntilDone();

    // The X should be 31 however it needs to be 
    // 22 for some reason.
    chassis.moveToPoint(22, 47, 2250, {.forwards = false, .maxSpeed = 80});
    chassis.waitUntilDone();
}

void getToThirdDropOffMotionChained() {
    chassis.moveToPoint(-50, 49, 2000, {.forwards = false, .minSpeed = 100});
    // Wait for movement until 3 inches before bringing
    // the intake up.
    chassis.waitUntil(3);
    PneumaticLoad.set_value(false);
    
    // Measure the distance of the left color distance from the wall.
    //float currentY = calculateDistanceFromRight();
    //chassis.setPose(-50, currentY, chassis.getPose().theta);
    //pros::lcd::print(2, "Y: %f\n", currentY); 
    //PneumaticLoad.set_value(false);
    
    // Go to the other (blue) side of the field
    chassis.moveToPoint(-35, 62, 2000, {.forwards = false, .minSpeed = 100});
    chassis.turnToHeading(270, 750, {.maxSpeed = 80, .minSpeed = 80});

    // The big straight starts here.    
    chassis.moveToPoint(30, 62, 4000, {.forwards = false, .minSpeed = 100});
    while (true) {
        if (chassis.getPose().x >= 30) {
            break;
        }
        float currentY = calculateDistanceFromRight();
        if (currentY < 59) {
            // We got too close to the goal.
            // Stop the drive and reset the pose to the X,Y where we are.
            chassis.cancelAllMotions();
            float currentX = calculateDistanceFromBack();
            chassis.setPose(currentX, currentY, chassis.getPose().theta);
            chassis.moveToPoint(30, 62, 4000, {.forwards = false, .minSpeed = 100});
            break;
        }
        pros::delay(10); 
    }
    
    // Now finally swing around to make sure we are alinged with the
    // goal.
    chassis.moveToPose(40, 46, 90, 2000, {.forwards = false});
    chassis.waitUntilDone();

    // Measure the distance of the right distance from the wall.
    float currentX = calculateDistanceFromBack();
    float currentY = calculateDistanceFromLeft();
    chassis.setPose(currentX, currentY, chassis.getPose().theta);
    pros::lcd::print(1, "X: %f\n", currentX); 
    pros::lcd::print(2, "Y: %f\n", currentY); 
    pros::delay(10000);

    // Now align with the goal.
    // The X should be 31 however it needs to be 
    // 22 for some reason. We backup till the back
    // distance sensor shows us that we are close to the goal.
    chassis.moveToPoint(22, 47, 2250, {.forwards = false, .maxSpeed = 80});
    chassis.waitUntilDone();
}

void getToFourthMatchLoader() {
    PneumaticLoad.set_value(true);
    chassis.moveToPoint(55, 47, 2000, {.maxSpeed = 60});
	chassis.waitUntilDone();
}

void getToFourthDropOff() {
    PneumaticLoad.set_value(false);
    chassis.moveToPoint(31, 47, 2250, {.forwards = false, .maxSpeed = 80});
    chassis.waitUntilDone();
}

void park() {
    PneumaticLoad.set_value(false);
    chassis.moveToPoint(42, 47, 1500);
    chassis.waitUntilDone();

    chassis.moveToPose(65, 10, 180, 1500);
    chassis.waitUntilDone();

    chassis.turnToHeading(180, 1000, {.direction = AngularDirection::CW_CLOCKWISE});
    chassis.waitUntilDone();

    // Read the distance from the left and back and reset the pose.
    float currentX = calculateDistanceFromLeft();
    float currentY = calculateDistanceFromBack();
    chassis.setPose(currentX, currentY, 180);
    //pros::lcd::print(1, "X: %f\n", currentX); 
    //pros::lcd::print(2, "Y: %f\n", currentY); 
    
    BFlywheel.move(127);
    chassis.moveToPoint(65, -10, 3000, {.maxSpeed = 127});
    chassis.waitUntilDone();
    //driveForwardTillDistanceUsingBackSensor(currentY + 8);
    // Keep running the intake till the balls are all out.
    pros::delay(2000);
    BFlywheel.brake();
}

void parkMotionChained() {
    PneumaticLoad.set_value(false);
    chassis.moveToPoint(42, 47, 1500, {.minSpeed = 100});
    chassis.moveToPose(65, 10, 180, 1500, {.minSpeed = 100});
    chassis.turnToHeading(180, 1000, {.direction = AngularDirection::CW_CLOCKWISE});
    chassis.waitUntilDone();

    // Read the distance from the left and back and reset the pose.
    float currentX = calculateDistanceFromLeft();
    float currentY = calculateDistanceFromBack();
    chassis.setPose(currentX, currentY, 180);
    //pros::lcd::print(1, "X: %f\n", currentX); 
    //pros::lcd::print(2, "Y: %f\n", currentY); 
    
    BFlywheel.move(127);
    chassis.moveToPoint(65, -10, 3000, {.maxSpeed = 127});
    chassis.waitUntilDone();
    //driveForwardTillDistanceUsingBackSensor(currentY + 8);
    // Keep running the intake till the balls are all out.
    pros::delay(2000);
    BFlywheel.brake();
}

void driveForwardTillDistanceUsingBackSensor(float distanceInInches) {
    // Turn on the 
    lemlib::Timer parkTimer(2000);
    chassis.arcade(127, 0);

    while (calculateDistanceFromBack() < distanceInInches && !parkTimer.isDone()) {
        pros::delay(10);
    }

    chassis.arcade(0, 0);
}

void skillsWithDistanceSensor() {
    getToFirstMatchLoader();
    matchLoad(80, 3000);
    chassis.setPose(55, -51, chassis.getPose().theta);
    //getToFirstDropOff();
    getToFirstDropOffMotionChained();
    outtake(1500);

    /*
    chassis.setPose(-31, -48, 270);
    getToSecondMatchLoader();
    matchLoad(60, 3000);
    chassis.setPose(-55, -48, chassis.getPose().theta);
    getToSecondDropOff();
    outtake(1500);
    chassis.setPose(-31, -48, 270);

    
    //getToThirdMatchLoader();
    getToThirdMatchLoaderMotionChained();
    matchLoad(60, 3000);
    chassis.setPose(-55, 49, chassis.getPose().theta);
    //getToThirdDropOff();
    getToThirdDropOffMotionChained();
    outtake(1500);
    chassis.turnToHeading(90, 1000);
    chassis.setPose(31, 47, 90); 

    getToFourthMatchLoader();
    matchLoad(60, 3000);
    chassis.setPose(55, 47, chassis.getPose().theta);
    getToFourthDropOff();
    outtake(1500);
    chassis.turnToHeading(90, 1000);
    chassis.setPose(31, 47, 90);

    //park();
    parkMotionChained();
    */
}