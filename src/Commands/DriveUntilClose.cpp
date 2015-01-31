#include "DriveUntilClose.h"

DriveUntilClose::DriveUntilClose()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::slidedrive);
	Requires(CommandBase::distancesensor);
}

// Called just before this Command runs the first time
void DriveUntilClose::Initialize()
{
	slidedrive->Drive(.5,0);
}

// Called repeatedly when this Command is scheduled to run
void DriveUntilClose::Execute()
{
	slidedrive->Drive(.5,0);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveUntilClose::IsFinished()
{
	return IsClose();
}

// Called once after isFinished returns true
void DriveUntilClose::End()
{
	slidedrive->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveUntilClose::Interrupted()
{
	End();
}

bool DriveUntilClose::IsClose()
{
	return distancesensor->GetDistance() < 30;
}
