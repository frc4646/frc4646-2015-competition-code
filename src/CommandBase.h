#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include "Commands/Command.h"
#include "Subsystems/ExampleSubsystem.h"
#include "OI.h"
#include "WPILib.h"
#include "Subsystems/Grabber.h"
#include "Subsystems/IntakeArms.h"
#include "Subsystems/IntakeRollers.h"
#include "Subsystems/PIDLift.h"
#include "Subsystems/SlideDrive.h"
#include "Subsystems/DistanceSensor.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
	CommandBase(char const *name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static ExampleSubsystem *examplesubsystem;
	static OI *oi;
	static Grabber* grabber;
	static IntakeArms* intakearms;
	static IntakeRollers* intakerollers;
	static PIDLift* lift;
	static SlideDrive* slidedrive;
	static DistanceSensor* distancesensor;
};

#endif
