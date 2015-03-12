#include "TotesMaGoats.h"
#include "GrabberCloseCommand.h"
#include "LiftToLevelCommand.h"
#include "DriveForDistance.h"
#include "../RobotMap.h"
#include "SlideForDistance.h"
#include "DriveUntilClose.h"
#include "DriveUntilCloseWithIntake.h"
#include "GrabberOpenCommand.h"
#include "LiftToBottomCommand.h"

TotesMaGoats::TotesMaGoats()
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
	AddSequential(new LiftToBottomCommand());
	AddSequential(new GrabberCloseCommand(), 0.01);
	AddSequential(new LiftToLevelCommand(LIFT_LEVEL_TWO));
	AddSequential(new SlideForDistance(38.5, 0.3));
	AddSequential(new DriveForDistance(40.5, -0.3));
	AddSequential(new SlideForDistance(38.5, -0.6));
	AddSequential(new DriveUntilCloseWithIntake(), 3);
	//Lower the tote onto the other tote
	AddSequential(new LiftToLevelCommand((LIFT_LEVEL_ONE + LIFT_LEVEL_TWO)/2.0));
	AddSequential(new GrabberOpenCommand(), 0.01);
	AddSequential(new LiftToBottomCommand());

	//Repeat all previous commands
	AddSequential(new GrabberCloseCommand(), 0.01);
	AddSequential(new LiftToLevelCommand(LIFT_LEVEL_TWO));
	AddSequential(new SlideForDistance(38.5, 0.3));
	AddSequential(new DriveForDistance(40.5, -0.3));
	AddSequential(new SlideForDistance(38.5, -0.6));
	AddSequential(new DriveUntilCloseWithIntake(), 3);
	AddSequential(new LiftToLevelCommand((LIFT_LEVEL_ONE + LIFT_LEVEL_TWO)/2.0));
	AddSequential(new GrabberOpenCommand(), 0.01);
	AddSequential(new LiftToBottomCommand());

	//Pick up the final stack of totes
	AddSequential(new GrabberCloseCommand(), 0.01);
	//Slide into the autonomous zone
	AddSequential(new SlideForDistance(107, 0.3));
	//TODO: Add timeouts to all autonomous commands. This is to prevent the
	//      robot from potentially never meeting the finished requirements
	//      for the commands and driving off haywire!!!

}
