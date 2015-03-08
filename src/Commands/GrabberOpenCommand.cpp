#include "GrabberOpenCommand.h"

GrabberOpenCommand::GrabberOpenCommand()
:CommandBase("GrabberOpenCommand")
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(grabber);
}

// Called just before this Command runs the first time
void GrabberOpenCommand::Initialize()
{
	grabber->Open();
}

// Called repeatedly when this Command is scheduled to run
void GrabberOpenCommand::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool GrabberOpenCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void GrabberOpenCommand::End()
{
	grabber->Idle();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GrabberOpenCommand::Interrupted()
{
	End();
}
