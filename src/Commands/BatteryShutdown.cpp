#include "BatteryShutdown.h"

BatteryShutdown::BatteryShutdown()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(batterymonitor);
}

// Called just before this Command runs the first time
void BatteryShutdown::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void BatteryShutdown::Execute()
{
	batterymonitor->CheckVoltage();
}

// Make this return true when this Command no longer needs to run execute()
bool BatteryShutdown::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void BatteryShutdown::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BatteryShutdown::Interrupted()
{

}
