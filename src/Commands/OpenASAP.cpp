#include "OpenASAP.h"

OpenASAP::OpenASAP()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(grabber);
}

// Called just before this Command runs the first time
void OpenASAP::Initialize()
{
	grabber->CanOpen();
	grabber->Open();
}

// Called repeatedly when this Command is scheduled to run
void OpenASAP::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool OpenASAP::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void OpenASAP::End()
{
	grabber->Idle();
	grabber->CanIdle();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OpenASAP::Interrupted()
{

}
