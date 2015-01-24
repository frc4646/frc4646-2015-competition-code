#include "SlideDrive.h"
#include "../RobotMap.h"
#include "../Commands/TankDrive.h"

SlideDrive::SlideDrive() :
		Subsystem("SlideDrive"),
		LeftSpeedController(LEFT_DRIVE_PORT),
		RightSpeedController(RIGHT_DRIVE_PORT),
		SlideSpeedController(SLIDE_DRIVE_PORT),
		DriveTrain(LeftSpeedController,RightSpeedController)
{

}

void SlideDrive::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new TankDrive());
}

void SlideDrive::HandleDrive(Joystick& left, Joystick& right) {
	DriveTrain.TankDrive(left,right);
}

void SlideDrive::HandleSlide(Joystick& left, Joystick& right) {
	SlideSpeedController.Set(left.GetRawAxis(2));
}

void SlideDrive::Stop() {
	DriveTrain.Drive(0,0);
	SlideSpeedController.Set(0);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
