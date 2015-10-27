#include "IntakeRollers.h"
#include "../RobotMap.h"
#include "../Commands/IntakeRollerCommand.h"

IntakeRollers::IntakeRollers() :
		Subsystem("IntakeRollers"),
		LeftController(LEFT_INTAKE_PORT),
		RightController(RIGHT_INTAKE_PORT)
{

}

void IntakeRollers::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new IntakeRollerCommand());
}

void IntakeRollers::SetLeft(float speed) {
	LeftController.Set(speed/2);
}

void IntakeRollers::SetRight(float speed) {
	RightController.Set(speed/2);
}

void IntakeRollers::Stop() {
	LeftController.Set(0);
	RightController.Set(0);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
