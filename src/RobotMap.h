#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
//const int LEFTMOTOR = 1;
//const int RIGHTMOTOR = 2;
const int LEFT_DRIVE_PORT = 9;
const int RIGHT_DRIVE_PORT = 8;
const int SLIDE_DRIVE_PORT = 7;
const int LIFT_DRIVE_PORT = 6;
const int LIFT_DRIVE_PORT2 = 5;
const int LEFT_INTAKE_PORT = 4;
const int RIGHT_INTAKE_PORT = 3;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;
const int GRABBER_OPEN_PORT = 1;
const int GRABBER_CLOSE_PORT = 2;
const int INTAKE_ARMS_PORT = 0; // oh yeah make these real too


const float LIFT_LOWER_SPEED = -0.5;
//TODO: consult drive team

const float BOX_HEIGHT = 12.1;
const float LIFT_LEVEL_ONE = 7;
const float LIFT_LEVEL_TWO = LIFT_LEVEL_ONE + BOX_HEIGHT;
const float LIFT_LEVEL_THREE = LIFT_LEVEL_TWO + BOX_HEIGHT;
const float LIFT_LEVEL_FOUR = LIFT_LEVEL_THREE + BOX_HEIGHT;
const float LIFT_LEVEL_FIVE = LIFT_LEVEL_FOUR + BOX_HEIGHT;
const float LIFT_LEVEL_SIX = LIFT_LEVEL_FIVE + BOX_HEIGHT;

const float DRIVE_MOTOR_SCALE = 1;

#endif
