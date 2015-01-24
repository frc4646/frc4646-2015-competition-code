#ifndef SlideDrive_H
#define SlideDrive_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class SlideDrive: public Subsystem
{
public:
	SlideDrive();
	void InitDefaultCommand();

	void HandleDrive(Joystick* left, Joystick* right);
	void HandleSlide(Joystick* left, Joystick* right);
	void Stop();

private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon LeftSpeedController;
	Talon RightSpeedController;
	Talon SlideSpeedController;
	RobotDrive DriveTrain;

};

#endif
