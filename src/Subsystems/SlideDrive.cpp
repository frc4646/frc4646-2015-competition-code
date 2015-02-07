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
		encoderLeft(2),
		encoderRight(3),
		encoderSlide(4),
		teleopChoice(new SendableChooser)
{
	DriveTrain.SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
	DriveTrain.SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
	DriveTrain.SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
	DriveTrain.SetInvertedMotor(RobotDrive::kRearRightMotor, true);
	teleopChoice->AddDefault("Tank drive", new TankDrive());
	teleopChoice->AddObject("Holonomic drive", new HolonomicDrive());
	SmartDashboard::PutData("Teleop mode", teleopChoice);
}

SlideDrive::~SlideDrive() {
	delete teleopChoice;
}

void SlideDrive::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand((Command*)teleopChoice->GetSelected());
}

void SlideDrive::HandleTankDrive(Joystick& left, Joystick& right) {
	if (TankEnabled)
	{
		DriveTrain.TankDrive(left,right);
	}
}

void SlideDrive::HandleSlide(Joystick& left, Joystick& right) {
	SlideSpeedController.Set(left.GetRawAxis(0));
}

void SlideDrive::HandleHolonomicDrive(Joystick& left, Joystick& right) {
	LeftSpeedController.Set(left.GetRawAxis(1) + right.GetRawAxis(0));
	RightSpeedController.Set(-(left.GetRawAxis(1)) - right.GetRawAxis(0));
	SlideSpeedController.Set(left.GetRawAxis(0));
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
