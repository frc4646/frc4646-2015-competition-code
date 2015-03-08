#include "DriveUntilCloseWithIntake.h"
#include "DriveUntilClose.h"
#include "IntakeUntilClose.h"
#include "IntakeArmsOpenCommand.h"
#include "IntakeArmsCloseCommand.h"

DriveUntilCloseWithIntake::DriveUntilCloseWithIntake()
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
	AddSequential(new IntakeArmsOpenCommand());
	AddParallel(new IntakeUntilClose(11));
	AddSequential(new DriveUntilClose(11));
	AddParallel(new IntakeArmsCloseCommand());
	AddSequential(new IntakeUntilClose(7));
}
