#ifndef Lift_H
#define Lift_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Lift: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Victor LiftSpeedControl;
	Victor LiftSpeedControl2;
	Encoder encoder;
	DigitalInput limitlower;
	DigitalInput limitupper;
public:
	Lift();
	void InitDefaultCommand();
	void Set(double speed);
	void Stop();
	Encoder& GetEncoder();

	DigitalInput& GetLimitLower();
};

#endif
