#include "LiftToLevelCommand.h"
#include "RobotMap.h"

LiftToLevelCommand::LiftToLevelCommand(double level):
liftlevel(level)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(lift);
}

// Called just before this Command runs the first time
void LiftToLevelCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void LiftToLevelCommand::Execute()
{
	SmartDashboard::PutData("EncoderValue", &lift->GetEncoder());
	if (fabs(lift->GetEncoder().GetDistance()) < liftlevel)
	{
		lift->Set(oi->GetLiftSpeed());
	}
	else
	{
		lift->Set(oi->GetLiftSpeed() * LIFT_LOWER_SPEED);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool LiftToLevelCommand::IsFinished()
{
	double error = fabs(lift->GetEncoder().GetDistance() - liftlevel);

	return error < 0.1;
}

// Called once after isFinished returns true
void LiftToLevelCommand::End()
{
	lift->Set(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftToLevelCommand::Interrupted()
{
	End();
}
