#include "LiftLowerCommand.h"
#include "../RobotMap.h"

LiftLowerCommand::LiftLowerCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(lift);
}

// Called just before this Command runs the first time
void LiftLowerCommand::Initialize()
{
	lift->Set(-oi->GetLiftSpeed());
}

// Called repeatedly when this Command is scheduled to run
void LiftLowerCommand::Execute()
{
	lift->Set(-oi->GetLiftSpeed());
}

// Make this return true when this Command no longer needs to run execute()
bool LiftLowerCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void LiftLowerCommand::End()
{
	lift->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftLowerCommand::Interrupted()
{
	End();
}
