#ifndef IntakeRollers_H
#define IntakeRollers_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class IntakeRollers: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Victor LeftController;
	Victor RightController;
public:
	IntakeRollers();
	void InitDefaultCommand();
	void SetLeft(float speed);
	void SetRight(float speed);
	void Stop();
};

#endif
