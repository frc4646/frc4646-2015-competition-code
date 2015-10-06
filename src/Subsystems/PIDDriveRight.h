#ifndef PIDDriveRight_H
#define PIDDriveRight_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "../CounterPIDSource.h"
#include "SingleEncoder.h"

class PIDDriveRight: public PIDSubsystem
{
public:
	PIDDriveRight();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();

	void Stop();
	SingleEncoder& GetRightEncoder();
private:

	Talon RightSpeedController;
	SingleEncoder encoderRight;
};

#endif
