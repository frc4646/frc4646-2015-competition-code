#ifndef SlideDrive_H
#define SlideDrive_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../CounterPIDSource.h"
#include "SingleEncoder.h"

class SlideDrive: public Subsystem
{
public:
	SlideDrive();
	~SlideDrive();
	void InitDefaultCommand();

	void HandleTankDrive(Joystick& left, Joystick& right);
	void HandleSlide(Joystick& left, Joystick& right);
	void HandleHolonomicDrive(Joystick& left, Joystick& right);
	void Stop();
	void SetTankEnabled(bool enable);
	void Drive(double speed, double curve);
	void DriveSlide(double speed);

	SingleEncoder& GetLeftEncoder();
	SingleEncoder& GetRightEncoder();
	SingleEncoder& GetSlideEncoder();

private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon LeftSpeedController;
	Talon RightSpeedController;
	Talon SlideSpeedController;
	RobotDrive DriveTrain;
	bool TankEnabled;
	SingleEncoder encoderLeft;
	SingleEncoder encoderRight;
	SingleEncoder encoderSlide;
	SendableChooser *teleopChoice;

};

#endif
