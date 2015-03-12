#include "SetLedHeight.h"
#include "RobotMap.h"

SetLedHeight::SetLedHeight():
CommandBase("SetLedHeight"),
counter(0)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(ledsystem);
}

// Called just before this Command runs the first time
void SetLedHeight::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void SetLedHeight::Execute()
{
	if (counter == 20)
	{
		ledsystem->sendLEDHeight(lift->GetEncoder().GetDistance()/INCH_PER_LED);
		counter = 0;
	}
	else
	{
		counter = counter+1;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool SetLedHeight::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void SetLedHeight::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetLedHeight::Interrupted()
{

}
