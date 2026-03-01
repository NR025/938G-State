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
//Declare auton utility variables.

//Declare auton functions.
//void _LateralMovement (float XCoord, float YCoord, int Time, bool Forward=true);
//void _AngularMovement (float Angle, int Time, bool Direction);

//Declare auton path functions.
void _PathLemT ();
void _PathLemN ();
void _PathLemL ();
void _PathLemR ();
void _PathLemA ();
void _PathLemS ();
void _PathLemSkills ();
void _PathLemSkillsWithFourthMatchLoader();
void _MovementWithDistanceSensor();

//Declare auton path functions.
void _OuttakeT ();
void _OuttakeL (); 
#endif //_PROS_AUTON_H_ 