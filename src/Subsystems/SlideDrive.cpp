#include "SlideDrive.h"
#include "../RobotMap.h"
#include "../Commands/TankDrive.h"
#include "../Commands/HolonomicDrive.h"

SlideDrive::SlideDrive() :
		Subsystem("SlideDrive"),
		LeftSpeedController(LEFT_DRIVE_PORT),
		RightSpeedController(RIGHT_DRIVE_PORT),
		SlideSpeedController(SLIDE_DRIVE_PORT),
		DriveTrain(LeftSpeedController,RightSpeedController),
		TankEnabled(true),
		encoderLeft(6),
		encoderRight(5),
		encoderSlide(7),
		teleopChoice(new SendableChooser)
{
	DriveTrain.SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
	DriveTrain.SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
	DriveTrain.SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
	DriveTrain.SetInvertedMotor(RobotDrive::kRearRightMotor, true);
//	DriveTrain.SetSafetyEnabled(false);
	const double distPerPulse = (6*M_PI/360);
	encoderLeft.SetDistancePerPulse(distPerPulse);
	encoderRight.SetDistancePerPulse(distPerPulse);
	encoderSlide.SetDistancePerPulse(distPerPulse);
	encoderLeft.Reset();
	encoderRight.Reset();
	encoderSlide.Reset();

	SmartDashboard::PutData("LeftEncoder", &encoderLeft);
	SmartDashboard::PutData("RightEncoder", &encoderRight);
	SmartDashboard::PutData("SlideEncoder", &encoderSlide);
}

SlideDrive::~SlideDrive() {
	delete teleopChoice;
}

void SlideDrive::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new TankDrive());
//	SetDefaultCommand(new HolonomicDrive());	//This line and the line below it should be commented out for tank drive
//	DriveTrain.SetSafetyEnabled(false); 		//The line above these should be uncommented too.
	//TODO: Non-sketchy way to switch these.
}

void SlideDrive::HandleTankDrive(Joystick& left, Joystick& right) {
	SmartDashboard::PutData("LeftEncoder", &encoderLeft);
	SmartDashboard::PutData("RightEncoder", &encoderRight);
	SmartDashboard::PutData("SlideEncoder", &encoderSlide);
	if (TankEnabled)
	{
		DriveTrain.TankDrive(left,right);
	}
}

void SlideDrive::HandleSlide(Joystick& left, Joystick& right) {
	SlideSpeedController.Set(-left.GetRawAxis(0));
}

void SlideDrive::HandleHolonomicDrive(Joystick& left, Joystick& right) {
	double leftSpeed	=(-left.GetRawAxis(1) + right.GetRawAxis(0))*abs(-left.GetRawAxis(1) + right.GetRawAxis(0));
	double rightSpeed	=(-(-left.GetRawAxis(1)) + right.GetRawAxis(0))*abs(-(-left.GetRawAxis(1)) + right.GetRawAxis(0));
	double slideSpeed	=(left.GetRawAxis(0))*abs(left.GetRawAxis(0));
//	LeftSpeedController.Set(-left.GetRawAxis(1) + right.GetRawAxis(0));
//	RightSpeedController.Set(-(-left.GetRawAxis(1)) + right.GetRawAxis(0));
//	SlideSpeedController.Set(left.GetRawAxis(0));
	LeftSpeedController.Set(leftSpeed);
	RightSpeedController.Set(rightSpeed);
	SlideSpeedController.Set(-slideSpeed);
}

void SlideDrive::Stop() {
	DriveTrain.Drive(0,0);
	SlideSpeedController.Set(0);
}

void SlideDrive::SetTankEnabled(bool enable) {
	TankEnabled = enable;
}

void SlideDrive::Drive(double speed, double curve) {
	DriveTrain.Drive(speed, curve);
}

void SlideDrive::DriveSlide(double speed) {
	SlideSpeedController.Set(speed);
}

SingleEncoder& SlideDrive::GetLeftEncoder() {
	return encoderLeft;
}

SingleEncoder& SlideDrive::GetRightEncoder() {
	return encoderRight;
}


SingleEncoder& SlideDrive::GetSlideEncoder() {
	return encoderSlide;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
