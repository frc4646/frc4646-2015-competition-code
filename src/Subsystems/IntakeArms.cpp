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
	IntakeSolenoid.Set(DoubleSolenoid::kForward);
}

void IntakeArms::Close() {
	IntakeSolenoid.Set(DoubleSolenoid::kReverse);
}

void IntakeArms::Idle() {
	IntakeSolenoid.Set(DoubleSolenoid::kOff);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
