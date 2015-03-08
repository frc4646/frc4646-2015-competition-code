#include "TurnForRevolutions.h"

TurnForRevolutions::TurnForRevolutions(double rotations, double power):
rotate(rotations),
power(power)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(slidedrive);
}

// Called just before this Command runs the first time
void TurnForRevolutions::Initialize()
{
	slidedrive->GetLeftEncoder().Reset();
}

// Called repeatedly when this Command is scheduled to run
void TurnForRevolutions::Execute()
{
	slidedrive->Drive(power, -1);
}

// Make this return true when this Command no longer needs to run execute()
bool TurnForRevolutions::IsFinished()
{
	return slidedrive->GetLeftEncoder().GetDistance() < (rotate*(30*M_PI));
}

// Called once after isFinished returns true
void TurnForRevolutions::End()
{
	slidedrive->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnForRevolutions::Interrupted()
{
	End();
}
