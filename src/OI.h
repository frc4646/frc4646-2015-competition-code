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
	Joystick DemoButton;
	JoystickButton GrabberClose;
	JoystickButton GrabberOpen;
	JoystickButton IntakeClose;
	JoystickButton LiftRaise;
	JoystickButton LiftLower;
	JoystickButton SlideOnly;
	JoystickButton SlideAndTank;
	JoystickButton StraightDrive;
	JoystickButton FastDrive;
	JoystickButton OpenEverything;
	JoystickButton LiftBottom;
	JoystickButton OpenCan;
	JoystickButton CloseCan;
	JoystickButton LiftLevelThree;
	JoystickButton LiftLevelFour;
	JoystickButton DemoModeButton;
//	JoystickButton LiftLevelFive;
//	JoystickButton LiftLevelSix;

};

#endif
