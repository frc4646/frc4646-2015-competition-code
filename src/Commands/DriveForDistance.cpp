#include "DriveForDistance.h"
#include "RobotMap.h"

DriveForDistance::DriveForDistance(double dist, double power):
encoderDist(dist),
motorPower(power)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(slidedrive);
}

// Called just before this Command runs the first time
void DriveForDistance::Initialize()
{
	slidedrive->Drive(motorPower,0);
}

// Called repeatedly when this Command is scheduled to run
void DriveForDistance::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool DriveForDistance::IsFinished()
{
	return slidedrive->GetLeftEncoder().Get() < encoderDist;
}

// Called once after isFinished returns true
void DriveForDistance::End()
{
	slidedrive->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForDistance::Interrupted()
{
	End();
}
