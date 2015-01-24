#include "IntakeArmsCloseCommand.h"

IntakeArmsCloseCommand::IntakeArmsCloseCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(intakearms);
}

// Called just before this Command runs the first time
void IntakeArmsCloseCommand::Initialize()
{
	intakearms->Close();
}

// Called repeatedly when this Command is scheduled to run
void IntakeArmsCloseCommand::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool IntakeArmsCloseCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void IntakeArmsCloseCommand::End()
{
	intakearms->Idle();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeArmsCloseCommand::Interrupted()
{
	End();
}
