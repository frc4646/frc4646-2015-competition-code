#include "SlideOnlyCommand.h"

SlideOnlyCommand::SlideOnlyCommand()
: CommandBase("SlideOnlyCommand")
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(slidedrive);
}

// Called just before this Command runs the first time
void SlideOnlyCommand::Initialize()
{
	slidedrive->SetTankEnabled(false);
}

// Called repeatedly when this Command is scheduled to run
void SlideOnlyCommand::Execute()
{
	slidedrive->HandleSlide(oi->GetLeftStick(), oi->GetRightStick());
	slidedrive->TankIdle();
}

// Make this return true when this Command no longer needs to run execute()
bool SlideOnlyCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void SlideOnlyCommand::End()
{
	slidedrive->SetTankEnabled(true);
	slidedrive->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SlideOnlyCommand::Interrupted()
{
	End();
}
