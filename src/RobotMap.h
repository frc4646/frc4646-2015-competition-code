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
const int LEFT_DRIVE_PORT = 0;
const int RIGHT_DRIVE_PORT = 1;
const int SLIDE_DRIVE_PORT = 2;
const int LIFT_DRIVE_PORT = 3;
const int LEFT_INTAKE_PORT = 4;
const int RIGHT_INTAKE_PORT = 5;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;
const int GRABBER_OPEN_PORT = 0;
const int GRABBER_CLOSE_PORT = 1;
const int INTAKE_ARMS_PORT = 2;

const float LIFT_RAISE_SPEED = 0.5;
const float LIFT_LOWER_SPEED = -0.1;

#endif
