#include "Lift.h"
#include "../RobotMap.h"

Lift::Lift() :
		Subsystem("Lift"),
		LiftSpeedControl(LIFT_DRIVE_PORT),
		LiftSpeedControl2(LIFT_DRIVE_PORT2)
{

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
// Put methods for controlling this subsystem
// here. Call these from Commands.
