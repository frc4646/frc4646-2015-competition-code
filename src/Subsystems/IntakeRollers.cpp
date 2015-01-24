#include "IntakeRollers.h"
#include "../RobotMap.h"

IntakeRollers::IntakeRollers() :
		Subsystem("IntakeRollers"),
		LeftController(LEFT_INTAKE_PORT),
		RightController(RIGHT_INTAKE_PORT)
{

}

void IntakeRollers::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void IntakeRollers::SetLeft(float speed) {
	LeftController.Set(speed);
}

void IntakeRollers::SetRight(float speed) {
	RightController.Set(speed);
}

void IntakeRollers::Stop() {
	LeftController.Set(0);
	RightController.Set(0);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
