#include "IntakeArmsOpenCommand.h"

IntakeArmsOpenCommand::IntakeArmsOpenCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(intakearms);
}

// Called just before this Command runs the first time
void IntakeArmsOpenCommand::Initialize()
{
	intakearms->Open();
}

// Called repeatedly when this Command is scheduled to run
void IntakeArmsOpenCommand::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool IntakeArmsOpenCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void IntakeArmsOpenCommand::End()
{
	intakearms->Idle();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeArmsOpenCommand::Interrupted()
{
	End();
}
