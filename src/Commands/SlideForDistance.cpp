#include "SlideForDistance.h"
#include "RobotMap.h"

SlideForDistance::SlideForDistance(double dist, double power):
encoderDist(dist),
motorPower(power)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(slidedrive);
}

// Called just before this Command runs the first time
void SlideForDistance::Initialize()
{
	slidedrive->GetSlideEncoder().Reset();
}

// Called repeatedly when this Command is scheduled to run
void SlideForDistance::Execute()
{
	slidedrive->DriveSlide(motorPower);
}

// Make this return true when this Command no longer needs to run execute()
bool SlideForDistance::IsFinished()
{
	return slidedrive->GetSlideEncoder().GetDistance() > encoderDist;
}

// Called once after isFinished returns true
void SlideForDistance::End()
{
	slidedrive->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SlideForDistance::Interrupted()
{
	End();
}
