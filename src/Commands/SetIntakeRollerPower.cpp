#include "SetIntakeRollerPower.h"

SetIntakeRollerPower::SetIntakeRollerPower(int power):
MotorPower(power)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(intakerollers);
}

// Called just before this Command runs the first time
void SetIntakeRollerPower::Initialize()
{
	intakerollers->SetLeft(MotorPower);
	intakerollers->SetRight(-MotorPower);
}

// Called repeatedly when this Command is scheduled to run
void SetIntakeRollerPower::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetIntakeRollerPower::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void SetIntakeRollerPower::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetIntakeRollerPower::Interrupted()
{
	End();
}
