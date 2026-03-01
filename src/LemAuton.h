/**
 * 2026 Pushback Tournament
 * Team 938G Coder ARM
 * Pros ProsAuton.h 
 */

//Include api.h.
#include "api.h"
#include "lemlib/api.hpp"

#ifndef _PROS_AUTON_H_
#define _PROS_AUTON_H_

#define LEFT_DISTANCE_SENSOR_TO_CENTER  6.5
#define RIGHT_DISTANCE_SENSOR_TO_CENTER  6.5
#define FRONT_DISTANCE_SENSOR_TO_CENTER  5
#define BACK_DISTANCE_SENSOR_TO_CENTER  6.5
#define HALF_FIELD_DISTANCE 72

// Utility functions.
float getDistanceInInches(pros::Distance& sensor);
void matchLoad();
void outtake();

// Path functions.
void getToFirstMatchLoader();

void _PathLemSkills ();
void _PathLemSkillsWithFourthMatchLoader();
void _MovementWithDistanceSensor();

#endif //_PROS_AUTON_H_ 