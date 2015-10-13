#include "PIDDrive.h"
#include "../RobotMap.h"

PIDDrive::PIDDrive() :
		Subsystem("PIDDrive")
{

}

void PIDDrive::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void PIDDrive::HandleTankDrive(Joystick& left, Joystick& right, bool fast) {
	double scale = .75;
	if (fast)
	{
		scale = 1;

	}
	LeftDrive.PIDWrite(left.GetRawAxis(1)*scale);
	RightDrive.PIDWrite(right.GetRawAxis(1)*scale);
}
