#include "AutoCommand.h"
#include "DriveUntilClose.h"

AutoCommand::AutoCommand()
: CommandGroup("AutoCommand")
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void AutoCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutoCommand::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool AutoCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutoCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoCommand::Interrupted()
{

}
