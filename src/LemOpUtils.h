/**
 * 2026 Pushback Tournament
 * Team 938G Coder ARM
 * Pros ProsOp.h
 */

//Include api.h.
#include "api.h"
#include "lemlib/api.hpp"

#ifndef _PROS_OP_H_
#define _PROS_OP_H_

//Declare utility variables.
extern double LeftY;
extern double RightX;
extern double PowerFactor;
extern double TurnFactor;
extern bool PneuDescore;
extern bool PneuMatchLoad;

//Declare opcontrol functions.
void DriveMovement();
void BlockMovement();
void PneuMovement();

#endif //_PROS_OP_H_