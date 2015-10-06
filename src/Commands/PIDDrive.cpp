#include "PIDDrive.h"
#include "RobotMap.h"

PIDDrive::PIDDrive(double dist, double power)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(piddriveleft);
	Requires(piddriveright);
}

// Called just before this Command runs the first time
void PIDDrive::Initialize()
{
	piddriveleft->GetLeftEncoder().Reset();
	piddriveright->GetRightEncoder().Reset();
}

// Called repeatedly when this Command is scheduled to run
void PIDDrive::Execute()
{
	piddriveleft->Drive(motorPower,0);
	piddriveright->Drive(motorPower,0);
}

// Make this return true when this Command no longer needs to run execute()
bool PIDDrive::IsFinished()
{
	return piddriveleft->GetLeftEncoder().GetDistance() > encoderDist && piddriveright->GetRightEncoder().GetDistance() > encoderDist;
}

// Called once after isFinished returns true
void PIDDrive::End()
{
	piddriveleft->Stop();
	piddriveright->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PIDDrive::Interrupted()
{
	End();
}
