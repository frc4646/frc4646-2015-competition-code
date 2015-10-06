#ifndef PIDDriveLeft_H
#define PIDDriveLeft_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"
#include "../CounterPIDSource.h"
#include "SingleEncoder.h"

class PIDDriveLeft: public PIDSubsystem
{
private:

	Talon LeftSpeedController;
	SingleEncoder encoderLeft;
public:
	PIDDriveLeft();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();

	void Stop();
	SingleEncoder& GetLeftEncoder();
};

#endif
