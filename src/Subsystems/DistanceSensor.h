#ifndef DistanceSensor_H
#define DistanceSensor_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DistanceSensor: public Subsystem
{
private:
	std::unique_ptr<AnalogInput> DistSensor;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	DistanceSensor();
	void InitDefaultCommand();
	double GetDistance();
};

#endif
