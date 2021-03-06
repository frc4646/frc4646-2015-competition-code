#include "GrabAndLift.h"
#include "GrabberCloseCommand.h"
#include "LiftForTime.h"
#include "ResetEncoder.h"
#include "LiftToLevelCommand.h"
#include "RobotMap.h"

GrabAndLift::GrabAndLift()
:CommandGroup("GrabAndLift")
{
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
	AddSequential(new GrabberCloseCommand(), 0.01);
	AddSequential(new ResetEncoder(), 0.01);
	AddSequential(new LiftToLevelCommand(LIFT_LEVEL_THREE, true));
}
