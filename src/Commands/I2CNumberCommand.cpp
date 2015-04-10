#include "I2CNumberCommand.h"

I2CNumberCommand::I2CNumberCommand(int NumberToSend):
numberToSend(NumberToSend)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(ledsystem);
}

// Called just before this Command runs the first time
void I2CNumberCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void I2CNumberCommand::Execute()
{
	ledsystem->sendNumber(numberToSend);
}

// Make this return true when this Command no longer needs to run execute()
bool I2CNumberCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void I2CNumberCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void I2CNumberCommand::Interrupted()
{

}
