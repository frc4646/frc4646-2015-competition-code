#include "SendTeamCommand.h"

SendTeamCommand::SendTeamCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);

	Requires(ledsystem);
}

// Called just before this Command runs the first time
void SendTeamCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void SendTeamCommand::Execute()
{
	ledsystem->sendTeam();
}

// Make this return true when this Command no longer needs to run execute()
bool SendTeamCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void SendTeamCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SendTeamCommand::Interrupted()
{
	End();
}
