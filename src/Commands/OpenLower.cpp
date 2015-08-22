#include "OpenLower.h"
#include "GrabberOpenCommand.h"
#include "LiftToBottomCommand.h"

OpenLower::OpenLower()
{
	AddSequential(new GrabberOpenCommand());
	AddSequential(new LiftToBottomCommand());

}
