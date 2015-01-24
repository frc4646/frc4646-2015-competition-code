#include "GrabberCloseCommand.h"

GrabberCloseCommand::GrabberCloseCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(grabber);
}

// Called just before this Command runs the first time
void GrabberCloseCommand::Initialize()
{
	grabber->Close();
}

// Called repeatedly when this Command is scheduled to run
void GrabberCloseCommand::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool GrabberCloseCommand::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void GrabberCloseCommand::End()
{
	grabber->Idle();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GrabberCloseCommand::Interrupted()
{
	End();
}
