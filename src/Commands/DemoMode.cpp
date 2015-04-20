#include "DemoMode.h"
#include "GrabberCloseCommand.h"
#include "GrabberOpenCommand.h"
#include "LiftToLevelCommand.h"
#include "ResetEncoder.h"
#include "RobotMap.h"
#include "LiftToTopCommand.h"
#include "LiftForTime.h"
#include "AutoIntakeCommand.h"
#include "IntakeArmsCloseCommand.h"
#include <unistd.h>

#include "Commands/WaitCommand.h"

DemoMode::DemoMode()
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
	for(int i=0; i < 1000; i++){
		AddSequential(new WaitCommand(1));
//		AddSequential(new LiftToTopCommand());
		AddSequential(new LiftToLevelCommand(LIFT_LEVEL_TWO));
//		AddSequential(new LiftForTime(-.2, .01));
		AddSequential(new WaitCommand(5));
		AddSequential(new LiftToLevelCommand(0, true)); //this should be lift to bottom but we took off the limit switch
		AddSequential(new WaitCommand(1));
		AddSequential(new GrabberOpenCommand(), 0.01);
		AddParallel(new IntakeArmsCloseCommand(), .25);
		AddSequential(new AutoIntakeCommand(-.5), .25);
		AddSequential(new WaitCommand(5));
		AddParallel(new IntakeArmsCloseCommand(), .25);
		AddSequential(new AutoIntakeCommand(.5), .25);
		AddSequential(new GrabberCloseCommand(), 0.01);
	}
}
