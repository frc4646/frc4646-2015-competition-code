#include "OI.h"
#include "Commands/GrabberCloseCommand.h"
#include "Commands/GrabberOpenCommand.h"
#include "Commands/IntakeArmsCloseCommand.h"
#include "Commands/IntakeArmsOpenCommand.h"
#include "Commands/LiftLowerCommand.h"
#include "Commands/LiftRaiseCommand.h"
#include "Commands/SlideCommand.h"
#include "Commands/TankAndSlideCommand.h"
#include "Commands/SlideOnlyCommand.h"
#include "Commands/StraightDriveCommand.h"
#include "Commands/LiftToBottomCommand.h"
#include "Commands/LiftToLevelCommand.h"
#include "RobotMap.h"

OI::OI():
	LeftStick(0),
	RightStick(1),
	MechanismStick(2),
	GrabberClose(&MechanismStick,1),
	GrabberOpen(&MechanismStick,2),
 	IntakeClose(&MechanismStick,3),
 	IntakeOpen(&MechanismStick,5),
 	LiftRaise(&MechanismStick,6),
 	LiftLower(&MechanismStick,4),
 	SlideOnly(&LeftStick,2),
	SlideAndTank(&LeftStick,1),
	StraightDrive(&LeftStick,3),
	LiftBottom(&MechanismStick,5),
	LiftLevelOne(&MechanismStick, 7),
	LiftLevelTwo(&MechanismStick, 9),
	LiftLevelThree(&MechanismStick, 11),
	LiftLevelFour(&MechanismStick, 8),
	LiftLevelFive(&MechanismStick, 10),
	LiftLevelSix(&MechanismStick, 12)
{
	// Process operator interface input here.
	GrabberClose.WhileHeld(new GrabberCloseCommand());
	GrabberOpen.WhileHeld(new GrabberOpenCommand());
	IntakeClose.WhileHeld(new IntakeArmsCloseCommand());
	IntakeOpen.WhileHeld(new IntakeArmsOpenCommand());

	LiftRaise.WhileHeld(new LiftRaiseCommand());
	LiftLower.WhileHeld(new LiftLowerCommand());
	SlideOnly.WhileHeld(new SlideOnlyCommand());
	SlideAndTank.WhileHeld(new TankAndSlideCommand());
	StraightDrive.WhileHeld(new StraightDriveCommand());
	LiftBottom.WhenPressed(new LiftToBottomCommand());
	LiftLevelOne.WhenPressed(new LiftToLevelCommand(LIFT_LEVEL_ONE));
	LiftLevelTwo.WhenPressed(new LiftToLevelCommand(LIFT_LEVEL_TWO));
	LiftLevelThree.WhenPressed(new LiftToLevelCommand(LIFT_LEVEL_THREE));
	LiftLevelFour.WhenPressed(new LiftToLevelCommand(LIFT_LEVEL_FOUR));
	LiftLevelFive.WhenPressed(new LiftToLevelCommand(LIFT_LEVEL_FIVE));
	LiftLevelSix.WhenPressed(new LiftToLevelCommand(LIFT_LEVEL_SIX));
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

double OI::GetLiftSpeed() {
	return (MechanismStick.GetRawAxis(3)*-0.5) + 0.5;
}
