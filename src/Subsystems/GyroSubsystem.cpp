#include "GyroSubsystem.h"
#include "../RobotMap.h"
#include <Commands/GetGyro.h>

GyroSubsystem::GyroSubsystem() :
		Subsystem("GyroSubsystem"),
		GyroSensor(new Gyro(1))
{
	SmartDashboard::PutData("GyroValue", GyroSensor.get());

}

void GyroSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new GetGyro());
}

double GyroSubsystem::GetAngle() {
	return GyroSensor->GetAngle();
}

void GyroSubsystem::SendData()
{
	SmartDashboard::PutData("GyroValue", GyroSensor.get());


}
// Put methods for controlling this subsystem
// here. Call these from Commands.
