#include "LiftForTime.h"

LiftForTime::LiftForTime(double Speed, double time):
speed(Speed)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(lift);
	SetTimeout(time);
}

// Called just before this Command runs the first time
void LiftForTime::Initialize()
{
	lift->Set(speed);
}

// Called repeatedly when this Command is scheduled to run
void LiftForTime::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool LiftForTime::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void LiftForTime::End()
{
	lift->Set(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftForTime::Interrupted()
{
	End();
}
