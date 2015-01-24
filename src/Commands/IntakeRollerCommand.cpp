#include "IntakeRollerCommand.h"

IntakeRollerCommand::IntakeRollerCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(intakerollers);
}

// Called just before this Command runs the first time
void IntakeRollerCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void IntakeRollerCommand::Execute()
{
	//FIX axis when we have controller
	intakerollers->SetLeft(oi->GetMechanismStick().GetRawAxis(0));
	intakerollers->SetRight(oi->GetMechanismStick().GetRawAxis(2));
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeRollerCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void IntakeRollerCommand::End()
{
	intakerollers->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeRollerCommand::Interrupted()
{
	End();
}
