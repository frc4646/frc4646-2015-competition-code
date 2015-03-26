#include "FastDriveCommand.h"

FastDriveCommand::FastDriveCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(slidedrive);
}

// Called just before this Command runs the first time
void FastDriveCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void FastDriveCommand::Execute()
{
	slidedrive->HandleTankDrive(oi->GetLeftStick(), oi->GetRightStick(), true);
}

// Make this return true when this Command no longer needs to run execute()
bool FastDriveCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void FastDriveCommand::End()
{
	slidedrive->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FastDriveCommand::Interrupted()
{
	End();
}
