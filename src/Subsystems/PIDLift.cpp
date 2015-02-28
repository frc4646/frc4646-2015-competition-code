#include "PIDLift.h"
#include "../RobotMap.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"
#include "./Commands/LiftIdle.h"

PIDLift::PIDLift() :
	PIDSubsystem("PIDLift", 1.0, 0.0, 0.0),
	LiftSpeedControl(LIFT_DRIVE_PORT),
	LiftSpeedControl2(LIFT_DRIVE_PORT2),
	encoder(9, 8),
	limitlower(4)
{
	encoder.Reset();
	encoder.SetPIDSourceParameter(PIDSource::kRate);
	encoder.SetDistancePerPulse((M_PI)/4096);
	encoder.SetReverseDirection(true);
	SetSetpoint(0);
	Enable();
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.

}

double PIDLift::ReturnPIDInput()
{
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;	
	return(encoder.GetRate());
}

void PIDLift::UsePIDOutput(double output)
{
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	LiftSpeedControl.Set(output);
	LiftSpeedControl2.Set(output);
}

void PIDLift::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new LiftIdle());
}

void PIDLift::Set(double speed) {
	SetSetpoint(speed);
}

void PIDLift::Stop() {
	SetSetpoint(0);
}

Encoder& PIDLift::GetEncoder() {
	return encoder;
}

DigitalInput& PIDLift::GetLimitLower() {
	return limitlower;
}
