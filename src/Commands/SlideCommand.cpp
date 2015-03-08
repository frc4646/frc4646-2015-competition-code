#include "SlideCommand.h"

SlideCommand::SlideCommand()
:CommandBase("SlideCommand")
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(slidedrive);
}

// Called just before this Command runs the first time
void SlideCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void SlideCommand::Execute()
{
	slidedrive->HandleSlide(oi->GetLeftStick(), oi->GetRightStick());
}

// Make this return true when this Command no longer needs to run execute()
bool SlideCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void SlideCommand::End()
{
	slidedrive->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SlideCommand::Interrupted()
{
	End();
}
