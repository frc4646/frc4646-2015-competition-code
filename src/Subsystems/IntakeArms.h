#ifndef IntakeArms_H
#define IntakeArms_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class IntakeArms: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Solenoid IntakeSolenoid;
public:
	IntakeArms();
	void InitDefaultCommand();
	void Open();
	void Close();
	void Idle();
};

#endif
