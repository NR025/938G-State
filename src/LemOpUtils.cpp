/**
 * 2026 Pushback Tournament
 * Team 938G Coder ARM
 * Pros ProsAuton.h 
 */

//Include initialized devices and ProsOp.h.
#include "Lem_Initialize.h"
#include "LemOpUtils.h"

//Define utility variables.
double LeftY = 0;
double RightX = 0;
double PowerFactor = 1;
double TurnFactor = 1;
bool PneuDescore = false;
bool PneuMatchLoad = false;
bool PneuOuttakeBool = true;
//Define drivetrain function.
void DriveMovement() {

    /*
    Arcade style controls with left joystick being power and right joystick being direction.
    Use power and turn factors to influence analog values used to move motor groups correctly.
     */


    int LeftY = MasterCont.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) * PowerFactor;
    int RightX = MasterCont.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X) * TurnFactor;
    chassis.arcade (LeftY, RightX);

}

//Define processing function.
void BlockMovement () {
    
    //Intake
    if (MasterCont.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {

        TFlywheel.brake();
        BFlywheel.move(127);

    }

    //High goal outake.
    else if (MasterCont.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){

        TFlywheel.move(127);
        BFlywheel.move(127);   

    }

    //Low goal outake.
    else if (MasterCont.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {

        TFlywheel.move(-127);
        BFlywheel.move(-127);
    }

    // Mid-Goal Outtake
    else if (MasterCont.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
        //if (MasterCont.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
            TFlywheel.move(60);
            BFlywheel.move(80);
        /*} 
        else {
            TFlywheel.move(80);
            BFlywheel.move(100);
        }*/
    } else if (MasterCont.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
            TFlywheel.move(40);
            BFlywheel.move(40);
        } 
    else {
        TFlywheel.brake();
        BFlywheel.brake();
    }
}

void PneuMovement () {

        //Descore
    if (MasterCont.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {

        if (PneuDescore == false) {
            
            PneumaticDescore.set_value(false);
            PneuDescore = true;
            pros::delay(250);

        } else {

            PneumaticDescore.set_value(true);
            PneuDescore = false;
            pros::delay(250);

        }

    }
    
   if (MasterCont.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {

        if (PneuMatchLoad== false) {

            PneumaticLoad.set_value(false);
            PneuMatchLoad = true;
            pros::delay(250);

        } else {

            //PneuLoad.retract();
            PneumaticLoad.set_value(true);
            PneuMatchLoad = false;
            pros::delay(250);

        }

    }

    // Outtake Pnue
    if (MasterCont.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {

        if (PneuOuttakeBool == false) {
            
            PneuOuttake.set_value(false);
            PneuOuttakeBool = true;
            pros::delay(250);

        } else {

            PneuOuttake.set_value(true);
            PneuOuttakeBool = false;
            pros::delay(250);
        }

    }

}