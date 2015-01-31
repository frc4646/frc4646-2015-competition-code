#include "StraightDriveCommand.h"

StraightDriveCommand::StraightDriveCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(slidedrive);
}

// Called just before this Command runs the first time
void StraightDriveCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void StraightDriveCommand::Execute()
{
	slidedrive->HandleDrive(oi->GetLeftStick(), oi->GetLeftStick());
}

// Make this return true when this Command no longer needs to run execute()
bool StraightDriveCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void StraightDriveCommand::End()
{
	slidedrive->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StraightDriveCommand::Interrupted()
{
	End();
}
