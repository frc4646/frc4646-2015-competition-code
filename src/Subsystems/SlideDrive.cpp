#include "SlideDrive.h"
#include "../RobotMap.h"
#include "../Commands/TankDrive.h"

SlideDrive::SlideDrive() :
		Subsystem("SlideDrive"),
		LeftSpeedController(LEFT_DRIVE_PORT),
		RightSpeedController(RIGHT_DRIVE_PORT),
		SlideSpeedController(SLIDE_DRIVE_PORT),
		DriveTrain(LeftSpeedController,RightSpeedController),
		TankEnabled(true)
{
	DriveTrain.SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
	DriveTrain.SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
	DriveTrain.SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
	DriveTrain.SetInvertedMotor(RobotDrive::kRearRightMotor, true);

}

void SlideDrive::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new TankDrive());
}

void SlideDrive::HandleDrive(Joystick& left, Joystick& right) {
	if (TankEnabled)
	{
		DriveTrain.TankDrive(left,right);
	}
}

void SlideDrive::HandleSlide(Joystick& left, Joystick& right) {
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

// Put methods for controlling this subsystem
// here. Call these from Commands.
