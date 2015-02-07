#ifndef SquareDrive_H
#define SquareDrive_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class SquareDrive: public CommandGroup
{
public:
	SquareDrive(double dist, double power);
};

#endif
