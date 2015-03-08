#include "DistanceSensor.h"
#include "../RobotMap.h"

DistanceSensor::DistanceSensor() :
		Subsystem("DistanceSensor"),
		DistSensor(new AnalogInput(0))
{
}

void DistanceSensor::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

double DistanceSensor::GetDistance() {
	return DistSensor->GetVoltage()*1024/5;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
