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
/*

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

*/

float getDistanceInInches(pros::Distance& sensor) {
    return sensor.get() * 0.0393701;
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

void outtake(int totalTime, int arcadeTime, int numExpectedBlocks) {
    TFlywheel.move(127);
    BFlywheel.move(127);
    chassis.arcade(-80, 0);
    PneumaticLoad.set_value(false);

    // Start a 5s timer.
    int arcadeCheckTime = totalTime - arcadeTime;
    if (arcadeCheckTime < 0) {
        arcadeCheckTime = 0;
    }

    lemlib::Timer loadTimer(totalTime);
    
    // 276 is the distance in mm that the sensor reads when there are no blocks
    // 100 is a distance threshold that was determined through testing. 
    int blockdistance = 80;
    int numBlocks = 0;
    int state = 0; // 0 = no blocks, 1 = one block
    while (numBlocks < numExpectedBlocks && !loadTimer.isDone()) {

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
    pros::delay(500);
    chassis.arcade(0, 0);
    TFlywheel.brake();
    BFlywheel.brake();
}

void outtakeWithDistanceSensor(int totalTime, int arcadeTime, int numExpectedBlocks) {
    // Start pushing back into the goal.
    chassis.arcade(-80, 0);
    while (true) {
        if (backDistanceSensor.get() <= 136) {
            break;
        }
        pros::delay(10);
    }

    TFlywheel.move(127);
    BFlywheel.move(127);
    PneumaticLoad.set_value(false);

    // Start a 5s timer.
    int arcadeCheckTime = totalTime - arcadeTime;
    if (arcadeCheckTime < 0) {
        arcadeCheckTime = 0;
    }

    lemlib::Timer loadTimer(totalTime);
    
    // 276 is the distance in mm that the sensor reads when there are no blocks
    // 85 is a distance threshold that was determined through testing. 
    int blockdistance = 80;
    int numBlocks = 0;
    int state = 0; // 0 = no blocks, 1 = one block
    while (numBlocks < numExpectedBlocks && !loadTimer.isDone()) {
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
        } else if (intakeDistance > blockdistance && state == 1) {
            // Flip the state back to zero so the next block
            // can be detected.
            state = 0;
            numBlocks++;
        } 

        pros::delay(10);
    }
    loadTimer.pause();
    //pros::lcd::print(1, "Blocks: %d Time: %d\n", numBlocks, loadTimer.getTimeLeft()); 


    // We can add more intelligence here, if the number of 
    // balls are lower than 6, then we could try to unjam the outtake.
    // we run it backward and then try to outtake again.
    // For now we dont do this, because if the block detection is
    // Broken then we will be in a bad situation where we keep running the outtake forever.

    // Run the outtake for a bit longer to ensure we
    // got all the blocks.
    pros::delay(500);
    chassis.arcade(0, 0);
    TFlywheel.brake();
    BFlywheel.brake();
}

void outtakeWithDistanceSensorAndJamDetection(int totalTime, int arcadeTime) {
    // Start pushing back into the goal.
    chassis.arcade(-80, 0);
    while (true) {
        if (backDistanceSensor.get() <= 136) {
            break;
        }
        pros::delay(10);
    }

    TFlywheel.move(127);
    BFlywheel.move(127);
    PneumaticLoad.set_value(false);

    // Start a 5s timer.
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

    // We expect the first block to show up before 400ms
    int timeToFirstBlock = 500;
    while (numBlocks < 6 && !loadTimer.isDone()) {
        if (numBlocks == 0) {
            if (loadTimer.getTimeLeft() > timeToFirstBlock) {
                // We might be jammed, because no blocks have come up
                // even though we have spent timeToFirstBlock time waiting.
                for (int i = 0; i <= 1; i++) {
                    pros::delay(20);
                    TFlywheel.move(-127);
                    BFlywheel.move(-127);
                    pros::delay(20);
                    TFlywheel.move(127);
                    BFlywheel.move(127);
                }
            }
        }

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
        } else if (intakeDistance > blockdistance && state == 1) {
            // Flip the state back to zero so the next block
            // can be detected.
            state = 0;
            numBlocks++;
        } 

        pros::delay(10);
    }
    loadTimer.pause();
    //pros::lcd::print(1, "Blocks: %d Time: %d\n", numBlocks, loadTimer.getTimeLeft()); 


    // We can add more intelligence here, if the number of 
    // balls are lower than 6, then we could try to unjam the outtake.
    // we run it backward and then try to outtake again.
    // For now we dont do this, because if the block detection is
    // Broken then we will be in a bad situation where we keep running the outtake forever.

    // Run the outtake for a bit longer to ensure we
    // got all the blocks.
    chassis.arcade(0, 0);
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

    // Start a timer.
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
        if (loadTimer.getTimeLeft() < 1000) {
            chassis.arcade(30, 0);
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
    pros::delay(900);
    chassis.arcade(0, 0);
}

// This function runs the intake till all the blocks are loaded.
// The idea is to use timing and the distancec sensor to determine when the
// blocks are loaded.
//
// 1.For some reason the intake is stopping for the first and the 
// second match loads. It should not stop for a while.
// 2. What happens if the first block is not detected? Then
//    the stuck logic will run unnecessarily. That add about 800ms 
//    of additional time.
void matchLoadWithStuckDetection(int arcadeSpeed, int time) {
    
    // Intake the blocks from the first match loader
    PneumaticLoad.set_value(true);
    
    //Start the flywheels and start driving forward.
    BFlywheel.move(127);
    chassis.arcade(arcadeSpeed, 0);

    // Start a timer.
    lemlib::Timer loadTimer(time);

    // 276 is the distance in mm that the sensor reads when there are no blocks
    // 100 is a distance threshold that was determined through testing.
    int blockdistance = 110;
    int numBlocks = 0;
    int state = 0; // 0 = no blocks, 1 = one block
    int timeToFirstBlock = 500;
    int numRetries = 0;
    while (numBlocks < 6 && !loadTimer.isDone()) {
        //pros::lcd::print(1, "B: %d T: %d\n", numBlocks, loadTimer.getTimePassed()); 
        // Only push back into the goal for a second, do not push back more.
        // When we push more, the battery power is distributed and 
        // the outtake does not work as well.
        if (loadTimer.getTimeLeft() < 1000) {
            chassis.arcade(30, 0);
        }

        int intakeDistance = intakeDistanceSensor.get();
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

        if (numBlocks == 0 && numRetries == 0 && loadTimer.getTimePassed() > timeToFirstBlock) {
            // This means we cannot seem to get the blocks.
            // backoff and try to slam back into the match loader.
            numRetries++;
            chassis.arcade(0, 0);
            chassis.arcade(-60, 0);
            pros::delay(250);
            chassis.arcade(40, 0);
            pros::delay(300);
            chassis.arcade(arcadeSpeed, 0);
        }

        pros::delay(20);
    }
    
    loadTimer.pause();

    // Run the intake for a bit longer to ensure we
    // got all the blocks.
    pros::delay(800);
    chassis.arcade(0, 0);
    //BFlywheel.brake();
}

void getToFirstMatchLoader() {
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
    chassis.setPose(49, -8, 180);
    PneumaticLoad.set_value(true);
    
    chassis.moveToPoint(49, -52, 5000);
    chassis.waitUntilDone();

    // Calculate the actual robot position and ensure we drove the right 
    // distance in case we are off using the front distance sensor.
    float currentY = calculateDistanceFromFront();
    chassis.setPose(49, -1 * currentY, 180);
    chassis.moveToPose(49, -52, 180, 2000, {.maxSpeed = 100});
    chassis.waitUntilDone();
   
    // Now turn towards the match loader.
    chassis.turnToHeading(90, 2000, {.maxSpeed = 60});
    chassis.waitUntilDone();
    
    // Drive torwards the match loader and intake.
    chassis.moveToPoint(51, -52, 2000);
    chassis.waitUntilDone();
}

void getToFirstDropOffMotionChained() {
    chassis.moveToPoint(50, -52, 2000, {.forwards = false, .minSpeed = 100});

    // Wait for movement until 3 inches before bringing
    // the intake up.
    chassis.waitUntil(3);
    PneumaticLoad.set_value(false);
    
    // Go to the other (blue) side of the field. We intentionally wait
    // for the initial turn to succeed because we want some accuracy.
    chassis.moveToPoint(35, -61, 2000, {.forwards = false, .maxSpeed = 80, .minSpeed = 80});
    chassis.turnToHeading(100, 1200, {.maxSpeed = 80});
    chassis.waitUntilDone();
    BFlywheel.brake();

    // This is the long straight.
    // We continuously measure the distance from the wall. 
    // If the robot gets too close to the goal, or too far from the wall.
    // then we break and reset.
    chassis.moveToPoint(-40, -61, 4000, {.forwards = false, .minSpeed = 100}); 
    while (true) {
        if (chassis.getPose().x <= -40) {
            break;
        }
        float currentY = calculateDistanceFromRight();
        if (currentY < 58.5 or currentY > 62.5) {
            // We got too close to the goal.
            // Reset the drivetrain location and continue.
            chassis.cancelAllMotions();
            //pros::lcd::print(1, "Y: %f\n", currentY); 
            chassis.setPose(chassis.getPose().x, -1 * currentY, chassis.getPose().theta);
            chassis.moveToPoint(-40, -61, 4000, {.forwards = false, .minSpeed = 100}); 
            pros::delay(20);
        }
        pros::delay(10); 
    }

    // Now swing and get to align with the goal and wait for this action to finish.
    chassis.moveToPose(-40, -46, 270, 2000, {.forwards = false, .maxSpeed = 80});
    chassis.waitUntilDone();

    // Now measure where we are.
    float currentX = calculateDistanceFromFront();
    float currentY = calculateDistanceFromLeft();
    chassis.setPose(-1 * currentX, -1 * currentY, chassis.getPose().theta);
    //pros::lcd::print(1, "X: %f\n", currentX); 
    //pros::lcd::print(2, "Y: %f\n", currentY); 
    
    // Now align with the goal.
    // The X should be -31 however it needs to be 
    // -25 for some reason. We backup till the back
    // distance sensor shows us that we are close to the goal.
    chassis.moveToPoint(-25, -48, 2250, {.forwards = false, .maxSpeed = 80});
    chassis.waitUntilDone();
}

void getToSecondMatchLoader() {
    PneumaticLoad.set_value(true);
    // THis is intentionally -47 instead of -48 because the
    // pickup was not working.
    chassis.moveToPoint(-55, -48, 2000, {.maxSpeed = 127});
	chassis.waitUntilDone();
}

void getToSecondDropOff() {
    chassis.moveToPoint(-30, -48, 2250, {.forwards = false, .maxSpeed = 127});
    chassis.waitUntilDone();
    BFlywheel.brake();
    PneumaticLoad.set_value(false);
}

void getToThirdMatchLoaderMotionChained() {
    int intendedX = -46;
    PneumaticLoad.set_value(true);
    chassis.moveToPoint(intendedX, -48, 2000, {.minSpeed = 50});
    chassis.turnToHeading(0, 1000);
    chassis.waitUntilDone();
    
    // We want to get to (-48, 49) however we drive a little less intentionally
    // and let the distance sensor fix us. So we drive uptil 30.
    chassis.moveToPoint(intendedX, 40, 4000);
    chassis.waitUntilDone();

    // Start of old code.
    // Calculate the actual robot position and ensure we drove the right 
    // distance in case we are off using the front distance sensor.
    float currentY = calculateDistanceFromFront();
    float currentX = calculateDistanceFromLeft();
    chassis.setPose(intendedX, currentY, 0);
    //pros::lcd::print(1, "Y: %f\n", currentY); 

    chassis.moveToPose(intendedX, 49.5, 0, 2000, {.maxSpeed = 60});
    chassis.waitUntilDone();

    // Turn towards the match loader.
    chassis.turnToHeading(270, 1000);
    chassis.waitUntilDone();

    // Bring down the loader and drive towards the loader.
    chassis.moveToPoint(-54, 48.5, 4000, {.maxSpeed = 80});
    chassis.waitUntilDone();
}



void getToThirdDropOffMotionChained() {
    chassis.moveToPoint(-50, 48, 2000, {.forwards = false, .minSpeed = 100});
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
    chassis.moveToPoint(-35, 62, 2000, {.forwards = false, .minSpeed = 50});
    BFlywheel.brake();

    // We use a slight angle that is pointing towards the wall to avoid
    // the robot having to correct its drive.
    chassis.turnToHeading(265, 750, {.maxSpeed = 80});
    chassis.waitUntilDone();

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
            //float currentX = calculateDistanceFromBack();
            chassis.setPose(chassis.getPose().x, currentY, chassis.getPose().theta);
            chassis.moveToPoint(30, 62, 4000, {.forwards = false, .minSpeed = 100});
            pros::delay(20);
        }
        pros::delay(10); 
    }
    
    // Now finally swing around to make sure we are alinged with the
    // goal.
    chassis.moveToPose(40, 46, 90, 3000, {.forwards = false});
    chassis.waitUntilDone();

    // Measure the distance of the right distance from the wall.
    float currentX = calculateDistanceFromFront();
    float currentY = calculateDistanceFromLeft();
    chassis.setPose(currentX, currentY, chassis.getPose().theta);
    //pros::lcd::print(1, "X: %f\n", currentX); 
    //pros::lcd::print(2, "Y: %f\n", currentY); 
    
    // Now align with the goal.
    // The X should be 31 however it needs to be 
    // 27 for some reason. We backup till the back
    // distance sensor shows us that we are close to the goal.
    chassis.moveToPoint(26, 47, 2000, {.forwards = false, .maxSpeed = 80});
    chassis.waitUntilDone();
}

void getToFourthMatchLoader() {
    PneumaticLoad.set_value(true);
    chassis.turnToHeading(90, 400);
    chassis.waitUntilDone();
    chassis.moveToPoint(55, 47, 2000, {.maxSpeed = 100});
	chassis.waitUntilDone();
}

void getToFourthDropOff() {
    chassis.moveToPoint(31, 47, 2250, {.forwards = false, .maxSpeed = 80});
    chassis.waitUntilDone();
    BFlywheel.brake();
}

void parkMotionChained() {
    PneumaticLoad.set_value(false);
    chassis.moveToPoint(42, 47, 1500, {.minSpeed = 100});
    chassis.moveToPose(68, 20, 180, 1500, {.minSpeed = 100});
    chassis.turnToHeading(180, 1000, {.direction = AngularDirection::CW_CLOCKWISE});
    chassis.waitUntilDone();
    pros::delay(200);

    // Read the distance from the left and back and reset the pose.
    float currentX = calculateDistanceFromLeft();
    float currentY = calculateDistanceFromBack();
    chassis.setPose(currentX, currentY, 180);
    //pros::lcd::print(1, "X: %f\n", currentX); 
    //pros::lcd::print(2, "Y: %f\n", currentY); 
    
    BFlywheel.move(127);
    chassis.moveToPoint(68, -13, 3000, {.maxSpeed = 127});
    chassis.waitUntilDone();
    //driveForwardTillDistanceUsingBackSensor();
    // Keep running the intake till the balls are all out.
    pros::delay(2000);
    BFlywheel.brake();
}

// Checks if we are stuck in addition to the
// distance checks. It determines that it is stuck if
// it has moved less than 0.5" in 300ms.
void driveForwardTillDistanceUsingBackSensor() {
    int timeout = 5000;
    int stuckTimeout = 300;
    int lastMoveTime = 0;
    float lastY = 0;
    float minimumDistance = 0.5;
    bool triedUnsticking = false;
    lemlib::Timer parkTimer(timeout);
    chassis.moveToPoint(68, -14, timeout, {.maxSpeed = 127, .minSpeed = 100});
    while (!parkTimer.isDone()) {
        float currentY = calculateDistanceFromBack();
        if (lastMoveTime == 0 || abs(lastY - currentY) > minimumDistance) {
            lastMoveTime = parkTimer.getTimePassed();
            lastY = currentY;
        }

        // If we have not moved for a little while then try unsticking.
        if (triedUnsticking == false && (parkTimer.getTimePassed() - lastMoveTime) > stuckTimeout) {
            // We have not moved in stuckTimeout time. So likely we are
            // stuck. Back off a little and try again.
            triedUnsticking = true;
            pros::lcd::print(1, "stuck Detected"); 
            chassis.cancelAllMotions();
            chassis.arcade(-100, 0);
            pros::delay(300);
            chassis.moveToPoint(68, -14, timeout, {.maxSpeed = 127, .minSpeed = 100});
        }

        int confidence = backDistanceSensor.get_confidence();
        if (currentY < 8 && confidence > 40) {
            break;
        }
        pros::lcd::print(2, "Y: %f confidence: %d\n", currentY, confidence); 
        pros::delay(10);
    }
    chassis.cancelAllMotions();
}

void skillsWithDistanceSensor() {
    // IF we want to save time we should try and
    // use 
    // outtakeWithDistanceSensor(3500, 1000);
    // And then change all the alignement with the
    // goals to be distance based. We push close to the
    // goal and the we use outtakeWithDistanceSensor.
    // So will have to change the getToXXXDropOffMotionChained
    // so that we are almost at the drop off.
    
    /*
    // Load the first set of blocks and dropoff.
    getToFirstMatchLoader();
    //matchLoad(80, 2500);
    matchLoadWithStuckDetection(60, 2500);
    chassis.setPose(55, -52, chassis.getPose().theta);
    getToFirstDropOffMotionChained();
    outtake(3000, 1200, 7);
    //outtakeWithDistanceSensor(3500, 2000, 7);
    chassis.setPose(-31, -48, 270);

    // Load the second set of blocks and dropoff.
    getToSecondMatchLoader();
    matchLoadWithStuckDetection(60, 2500);
    chassis.setPose(-55, -48, chassis.getPose().theta);
    getToSecondDropOff();
    //outtake(3500, 1000);
    outtakeWithDistanceSensor(3000, 1200, 6);
    chassis.setPose(-31, -48, 270);
    
    // Load the third set of blocks and dropoff.
    getToThirdMatchLoaderMotionChained();
    matchLoadWithStuckDetection(60, 2500);
    chassis.setPose(-55, 48, chassis.getPose().theta);
    getToThirdDropOffMotionChained();
    outtake(3000, 1200, 6);
    //outtakeWithDistanceSensor(3500, 1500, 6);
    //chassis.turnToHeading(90, 1000);
    chassis.setPose(31, 47, chassis.getPose().theta); 

    // Load the fourth set of blocks and drop off.
    getToFourthMatchLoader();
    matchLoadWithStuckDetection(60, 2500);
    chassis.setPose(55, 47, chassis.getPose().theta);
    getToFourthDropOff();
    //outtake(3500, 1500);
    outtakeWithDistanceSensor(3000, 1200, 6);
    //chassis.turnToHeading(90, 1000);
    */
    chassis.setPose(31, 47, chassis.getPose().theta);
    chassis.setPose(31, 47, 90);
    
    parkMotionChained();
}

