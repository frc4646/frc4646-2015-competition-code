#include "LiftToTopCommand.h"
#include "RobotMap.h"

LiftToTopCommand::LiftToTopCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(lift);
}

// Called just before this Command runs the first time
void LiftToTopCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void LiftToTopCommand::Execute()
{
//	lift->Set(oi->GetLiftSpeed());
	lift->Set(0.25); // heve to be careful to not kill the switch or kevlar
}

// Make this return true when this Command no longer needs to run execute()
bool LiftToTopCommand::IsFinished()
{
	return !lift->GetLimitUpper().Get();
}

// Called once after isFinished returns true
void LiftToTopCommand::End()
{
	lift->Set(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftToTopCommand::Interrupted()
{
	End();
}
