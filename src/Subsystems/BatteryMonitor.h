#ifndef BatteryMonitor_H
#define BatteryMonitor_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class BatteryMonitor: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	int batLowCount;
public:
	BatteryMonitor();
	void InitDefaultCommand();
	void CheckVoltage();
};

#endif
