#include "CanOpenCommand.h"

CanOpenCommand::CanOpenCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(grabber);
}

// Called just before this Command runs the first time
void CanOpenCommand::Initialize()
{
	grabber->CanOpen();
}

// Called repeatedly when this Command is scheduled to run
void CanOpenCommand::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool CanOpenCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void CanOpenCommand::End()
{
	grabber->CanIdle();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CanOpenCommand::Interrupted()
{

}
