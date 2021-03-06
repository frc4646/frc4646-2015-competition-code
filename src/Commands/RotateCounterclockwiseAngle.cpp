#include "RotateCounterclockwiseAngle.h"

RotateCounterclockwiseAngle::RotateCounterclockwiseAngle(double angle, double power):
//		StartingAngle(gyrosubsystem->GetAngle()),
		StartingPower(power),
		FinishingAngle(angle)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(slidedrive);
	Requires(gyrosubsystem);
}

// Called just before this Command runs the first time
void RotateCounterclockwiseAngle::Initialize()
{
	StartingAngle = gyrosubsystem->GetAngle();
}

// Called repeatedly when this Command is scheduled to run
void RotateCounterclockwiseAngle::Execute()
{
	slidedrive->Drive(StartingPower,1);
}

// Make this return true when this Command no longer needs to run execute()
bool RotateCounterclockwiseAngle::IsFinished()
{
	return (gyrosubsystem->GetAngle()-StartingAngle) < -(FinishingAngle);
}

// Called once after isFinished returns true
void RotateCounterclockwiseAngle::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RotateCounterclockwiseAngle::Interrupted()
{

}
