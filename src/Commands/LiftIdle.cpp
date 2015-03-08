#include "LiftIdle.h"

LiftIdle::LiftIdle()
:CommandBase("LiftIdle")
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(lift);
}

// Called just before this Command runs the first time
void LiftIdle::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void LiftIdle::Execute()
{
	lift->Set(0);
}

// Make this return true when this Command no longer needs to run execute()
bool LiftIdle::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void LiftIdle::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftIdle::Interrupted()
{

}
