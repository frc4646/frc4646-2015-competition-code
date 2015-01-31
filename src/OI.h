#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{

public:
	OI();
	Joystick& GetLeftStick();
	Joystick& GetRightStick();
	Joystick& GetMechanismStick();

	double GetLiftSpeed();

private:
	Joystick LeftStick;
	Joystick RightStick;
	Joystick MechanismStick;
	JoystickButton GrabberClose;
	JoystickButton GrabberOpen;
	JoystickButton IntakeClose;
	JoystickButton LiftRaise;
	JoystickButton LiftLower;
	JoystickButton SlideOnly;
	JoystickButton SlideAndTank;
	JoystickButton StraightDrive;
};

#endif
