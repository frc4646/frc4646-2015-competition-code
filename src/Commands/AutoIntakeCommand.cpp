#include "AutoIntakeCommand.h"

AutoIntakeCommand::AutoIntakeCommand(double Power):
power(Power)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(intakerollers);
}

// Called just before this Command runs the first time
void AutoIntakeCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutoIntakeCommand::Execute()
{
	intakerollers->SetLeft(power);
	intakerollers->SetRight(-power);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoIntakeCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutoIntakeCommand::End()
{
	End();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoIntakeCommand::Interrupted()
{

}
