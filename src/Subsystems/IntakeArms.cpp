#include "IntakeArms.h"
#include "../RobotMap.h"

IntakeArms::IntakeArms() :
		Subsystem("IntakeArms"),
		IntakeSolenoid(INTAKE_ARMS_PORT)
{

}

void IntakeArms::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void IntakeArms::Open() {
	IntakeSolenoid.Set(true);
}

void IntakeArms::Close() {
	IntakeSolenoid.Set(false);
}

void IntakeArms::Idle() {
	IntakeSolenoid.Set(false);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
