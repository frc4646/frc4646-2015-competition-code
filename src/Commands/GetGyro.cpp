#include "GetGyro.h"
#include <Subsystems/GyroSubsystem.h>

GetGyro::GetGyro()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(gyrosubsystem);
}

// Called just before this Command runs the first time
void GetGyro::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void GetGyro::Execute()
{
	gyrosubsystem->SendData();
}

// Make this return true when this Command no longer needs to run execute()
bool GetGyro::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void GetGyro::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GetGyro::Interrupted()
{

}
