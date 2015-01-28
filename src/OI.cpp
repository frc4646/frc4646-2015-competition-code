#include "OI.h"
#include "Commands/GrabberCloseCommand.h"
#include "Commands/GrabberOpenCommand.h"
#include "Commands/IntakeArmsCloseCommand.h"
#include "Commands/LiftLowerCommand.h"
#include "Commands/LiftRaiseCommand.h"
#include "Commands/SlideCommand.h"
#include "Commands/TankAndSlideCommand.h"

OI::OI():
	LeftStick(0),
	RightStick(1),
	MechanismStick(2),
	GrabberClose(&MechanismStick,1),
	GrabberOpen(&MechanismStick,2),
 	IntakeClose(&MechanismStick,3),
 	LiftRaise(&MechanismStick,6),
 	LiftLower(&MechanismStick,4),
 	SlideOnly(&LeftStick,2),
	SlideAndTank(&LeftStick,1)
{
	// Process operator interface input here.
	GrabberClose.WhenPressed(new GrabberCloseCommand());
	GrabberOpen.WhenPressed(new GrabberOpenCommand());
	IntakeClose.WhileHeld(new IntakeArmsCloseCommand());
	LiftRaise.WhileHeld(new LiftRaiseCommand());
	LiftLower.WhileHeld(new LiftLowerCommand());
	SlideOnly.WhileHeld(new SlideCommand());
	SlideAndTank.WhileHeld(new TankAndSlideCommand());
}

Joystick& OI::GetLeftStick() {
	return LeftStick;
}

Joystick& OI::GetRightStick() {
	return RightStick;
}

Joystick& OI::GetMechanismStick() {
	return MechanismStick;
}
