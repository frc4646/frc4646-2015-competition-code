#include "TankAndSlideCommand.h"

TankAndSlideCommand::TankAndSlideCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(slidedrive);
}

// Called just before this Command runs the first time
void TankAndSlideCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void TankAndSlideCommand::Execute()
{
	slidedrive->HandleTankDrive(oi->GetLeftStick(), oi->GetRightStick());
	slidedrive->HandleSlide(oi->GetLeftStick(), oi->GetRightStick());
}

// Make this return true when this Command no longer needs to run execute()
bool TankAndSlideCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void TankAndSlideCommand::End()
{
	slidedrive->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TankAndSlideCommand::Interrupted()
{
	End();
}
