#include "IntakeUntilClose.h"

IntakeUntilClose::IntakeUntilClose(double finalObjectDistance)
: CommandBase("IntakeUntilClose"),
  m_finalObjectDistance(finalObjectDistance)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::intakerollers);
	Requires(CommandBase::distancesensor);
}

// Called just before this Command runs the first time
void IntakeUntilClose::Initialize()
{
	intakerollers->SetLeft(0);
	intakerollers->SetRight(0);
}

// Called repeatedly when this Command is scheduled to run
void IntakeUntilClose::Execute()
{
	intakerollers->SetLeft(1);
	intakerollers->SetRight(-1);
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeUntilClose::IsFinished()
{
	return IsClose();
}

// Called once after isFinished returns true
void IntakeUntilClose::End()
{
	intakerollers->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeUntilClose::Interrupted()
{
	End();
}

bool IntakeUntilClose::IsClose()
{
	return distancesensor->GetDistance() < m_finalObjectDistance;
}
