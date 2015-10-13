#ifndef PIDDrive_H
#define PIDDrive_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "PIDDriveLeft.h"
#include "PIDDriveRight.h";

class PIDDrive: public Subsystem
{

public:
	PIDDrive();
	void InitDefaultCommand();
	void HandleTankDrive(Joystick& left, Joystick& right, bool fast=false);

private:
	PIDDriveLeft LeftDrive;
	PIDDriveRight RightDrive;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
};

#endif
