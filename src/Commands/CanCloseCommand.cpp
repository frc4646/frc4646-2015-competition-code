#include "CanCloseCommand.h"

CanCloseCommand::CanCloseCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(grabber);
}

// Called just before this Command runs the first time
void CanCloseCommand::Initialize()
{
	grabber->CanClose();
}

// Called repeatedly when this Command is scheduled to run
void CanCloseCommand::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool CanCloseCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void CanCloseCommand::End()
{
	grabber->CanIdle();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CanCloseCommand::Interrupted()
{

}
