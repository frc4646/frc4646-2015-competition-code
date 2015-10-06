#include "PIDDriveRight.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"

PIDDriveRight::PIDDriveRight() :
		PIDSubsystem("PIDDriveRight", 1.0, 0.0, 0.0),
		encoderRight(6),
		RightSpeedController(RIGHT_DRIVE_PORT)
{
// Use these to get going:
// SetSetpoint() -  Sets where the PID controller should move the system
//                  to
// Enable() - Enables the PID controller.
encoderRight.Reset();
encoderRight.SetPIDSourceParameter(PIDSource::kRate);
encoderRight.SetDistancePerPulse((M_PI)/4096);
SetSetpoint(0);
Enable();
}

double PIDDriveRight::ReturnPIDInput()
{
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;	
	encoderRight.GetRate();
}

void PIDDriveRight::UsePIDOutput(double output)
{
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	RightSpeedController.SetSpeed(output);
}

void PIDDriveRight::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
}


void PIDDriveRight::Stop() {
}


