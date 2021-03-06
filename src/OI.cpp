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
#include "Commands/FastDriveCommand.h"
#include "Commands/DemoMode.h"
#include "Commands/CanOpenCommand.h"
#include "Commands/OpenASAP.h"
#include "Commands/CanCloseCommand.h"
#include "RobotMap.h"

OI::OI():
	LeftStick(0),
	RightStick(1),
	MechanismStick(2),
	DemoButton(3),
	GrabberClose(&MechanismStick,1),
	GrabberOpen(&MechanismStick,3),
 	IntakeClose(&MechanismStick,11),
 	LiftRaise(&MechanismStick,6),
 	LiftLower(&MechanismStick,4),
 	SlideOnly(&LeftStick,2),
	SlideAndTank(&LeftStick,1),
	StraightDrive(&LeftStick,3),
	FastDrive(&RightStick,1),
	OpenEverything(&RightStick,4),
	LiftBottom(&MechanismStick,5),
	OpenCan(&MechanismStick, 9),
	CloseCan(&MechanismStick, 10),
	LiftLevelThree(&MechanismStick, 7),
	LiftLevelFour(&MechanismStick, 8),
	DemoModeButton(&DemoButton,1)
//	LiftLevelFive(&MechanismStick, 7),
//	LiftLevelSix(&MechanismStick, 8)
{
	// Process operator interface input here.

	SlideOnly.WhileHeld(new SlideOnlyCommand());
	SlideAndTank.WhileHeld(new TankAndSlideCommand());
	StraightDrive.WhileHeld(new StraightDriveCommand());
	FastDrive.WhileHeld(new FastDriveCommand());
	GrabberClose.WhileHeld(new GrabberCloseCommand());
	GrabberOpen.WhileHeld(new GrabberOpenCommand());
	IntakeClose.WhileHeld(new IntakeArmsCloseCommand());
	LiftRaise.WhileHeld(new LiftRaiseCommand());
	LiftLower.WhileHeld(new LiftLowerCommand());
	OpenEverything.WhileHeld(new OpenASAP());
	OpenCan.WhileHeld(new CanOpenCommand());
	CloseCan.WhileHeld(new CanCloseCommand());
//	LiftBottom.WhenPressed(new LiftToBottomCommand());
//	LiftLevelOne.WhenPressed(new LiftToLevelCommand(LIFT_LEVEL_ONE));
//	LiftLevelTwo.WhenPressed(new LiftToLevelCommand(LIFT_LEVEL_TWO));
//	LiftLevelThree.WhenPressed(new LiftToLevelCommand(LIFT_LEVEL_THREE));
//	LiftLevelFour.WhenPressed(new LiftToLevelCommand(LIFT_LEVEL_FOUR));
	DemoModeButton.WhenPressed(new DemoMode());
//	LiftLevelFive.WhenPressed(new LiftToLevelCommand(LIFT_LEVEL_FIVE));
//	LiftLevelSix.WhenPressed(new LiftToLevelCommand(LIFT_LEVEL_SIX));
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
	return (MechanismStick.GetRawAxis(3)*-0.4) + 0.6;
}
