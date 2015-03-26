#include "Lift.h"
#include "../RobotMap.h"


Lift::Lift() :
		Subsystem("Lift"),
		LiftSpeedControl(LIFT_DRIVE_PORT),
		LiftSpeedControl2(LIFT_DRIVE_PORT2),
		encoder(9, 8),
		limitlower(4),
		limitupper(3)
{
	encoder.Reset();
	encoder.SetPIDSourceParameter(PIDSource::kRate);
	encoder.SetDistancePerPulse((M_PI)/4096.0);
	encoder.SetReverseDirection(true);
}

void Lift::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Lift::Set(double speed) {
	if(speed > 0)
	{
		if(!limitupper.Get())
		{
			speed = 0;
		}
	}
	LiftSpeedControl.Set(speed);
	LiftSpeedControl2.Set(speed);
}

void Lift::Stop() {
	LiftSpeedControl.Set(0);
	LiftSpeedControl2.Set(0);
}

Encoder& Lift::GetEncoder() {
	return encoder;
}

DigitalInput& Lift::GetLimitLower() {
	return limitlower;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
