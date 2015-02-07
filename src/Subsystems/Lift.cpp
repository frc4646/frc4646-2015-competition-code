#include "Lift.h"
#include "../RobotMap.h"
#include "math.h"

Lift::Lift() :
		Subsystem("Lift"),
		LiftSpeedControl(LIFT_DRIVE_PORT),
		LiftSpeedControl2(LIFT_DRIVE_PORT2),
		encoder(9, 8),
		limitlower(0),
		limitupper(1)
{
	encoder.Reset();
	encoder.SetPIDSourceParameter(PIDSource::kRate);
	encoder.SetDistancePerPulse((2*M_PI)/2048);
	encoder.SetReverseDirection(true);
}

void Lift::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Lift::Set(double speed) {
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

DigitalInput& Lift::GetLimitUpper() {
	return limitupper;
}

DigitalInput& Lift::GetLimitLower() {
	return limitlower;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
