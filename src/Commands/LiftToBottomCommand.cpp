#include "LiftToBottomCommand.h"
#include "RobotMap.h"

LiftToBottomCommand::LiftToBottomCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(lift);
}

// Called just before this Command runs the first time
void LiftToBottomCommand::Initialize()
{
	lift->Set(LIFT_LOWER_SPEED);
}

// Called repeatedly when this Command is scheduled to run
void LiftToBottomCommand::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool LiftToBottomCommand::IsFinished()
{
	return !lift->GetLimitLower().Get();
}

// Called once after isFinished returns true
void LiftToBottomCommand::End()
{
	lift->Set(0);
	lift->GetEncoder().Reset();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftToBottomCommand::Interrupted()
{
	End();
}
