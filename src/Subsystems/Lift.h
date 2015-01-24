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
public:
	Lift();
	void InitDefaultCommand();
	void Set(double speed);
	void Stop();
};

#endif
