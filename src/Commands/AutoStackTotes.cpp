#include "AutoStackTotes.h"
#include "GrabAndLift.h"
#include "DriveUntilClose.h"
#include "StackAndLower.h"
#include "DriveForDistance.h"
#include "SlideForDistance.h"

AutoStackTotes::AutoStackTotes()
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
//	AddSequential(new GrabAndLift());
//	AddSequential(new DriveUntilClose(), 7);
//	AddSequential(new StackAndLower());
//	AddSequential(new GrabAndLift());
	AddSequential(new DriveForDistance(18*M_PI, 0.2));
	AddSequential(new SlideForDistance(18*M_PI, 0.2));
}
