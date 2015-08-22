#ifndef GyroSubsystem_H
#define GyroSubsystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class GyroSubsystem: public Subsystem
{
private:
	std::unique_ptr<Gyro> GyroSensor;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	GyroSubsystem();
	void InitDefaultCommand();
	double GetAngle();
	void SendData();
};

#endif
