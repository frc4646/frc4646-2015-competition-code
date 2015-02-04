#include "HolonomicDrive.h"

HolonomicDrive::HolonomicDrive()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(slidedrive);
}

// Called just before this Command runs the first time
void HolonomicDrive::Initialize()
{
	slidedrive->HandleHolonomicDrive(oi->GetLeftStick(), oi->GetRightStick());
}

// Called repeatedly when this Command is scheduled to run
void HolonomicDrive::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool HolonomicDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void HolonomicDrive::End()
{
	slidedrive->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HolonomicDrive::Interrupted()
{
	End();
}
