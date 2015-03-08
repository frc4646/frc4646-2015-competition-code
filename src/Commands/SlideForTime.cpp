#include "SlideForTime.h"

SlideForTime::SlideForTime(double power, double time):
CommandBase("SlideForTime"),
driveSpeed(power)
{
	Requires(slidedrive);
	SetTimeout(time);
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void SlideForTime::Initialize()
{
	slidedrive->DriveSlide(driveSpeed);
}

// Called repeatedly when this Command is scheduled to run
void SlideForTime::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SlideForTime::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void SlideForTime::End()
{
	slidedrive->DriveSlide(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SlideForTime::Interrupted()
{
	End();
}
