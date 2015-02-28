#ifndef PIDLift_H
#define PIDLift_H

#include "Commands/PIDSubsystem.h"
#include "WPILib.h"

class PIDLift: public PIDSubsystem
{
private:
	Victor LiftSpeedControl;
	Victor LiftSpeedControl2;
	Encoder encoder;
	DigitalInput limitlower;
public:
	PIDLift();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();

	void Set(double speed);
	void Stop();
	Encoder& GetEncoder();

	DigitalInput& GetLimitLower();

};

#endif
