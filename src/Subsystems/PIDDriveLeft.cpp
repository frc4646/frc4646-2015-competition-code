#include "PIDDriveLeft.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"

PIDDriveLeft::PIDDriveLeft() :
	PIDSubsystem("PIDDriveLeft", 1.0, 0.0, 0.0),
	encoderLeft(5),
	LeftSpeedController(LEFT_DRIVE_PORT)
{
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
	encoderLeft.Reset();
	encoderLeft.SetPIDSourceParameter(PIDSource::kRate);
	encoderLeft.SetDistancePerPulse((M_PI)/4096);
	SetSetpoint(0);
	Enable();
}

double PIDDriveLeft::ReturnPIDInput()
{
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	double rate = encoderLeft.GetRate();
	if(rate > 120.0){
		rate = 120.0;
	}else if(rate < -120){
		rate = -120;
	}
	return rate/120; //120 is max speed in in/s
}

void PIDDriveLeft::UsePIDOutput(double output)
{
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	LeftSpeedController.SetSpeed(output);
}

void PIDDriveLeft::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//setDefaultCommand(new MySpecialCommand());
}

void PIDDriveLeft::Stop() {
}
