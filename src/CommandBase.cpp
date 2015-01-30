#include "CommandBase.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
ExampleSubsystem* CommandBase::examplesubsystem = NULL;
OI* CommandBase::oi = NULL;
Grabber* CommandBase::grabber = NULL;
IntakeArms* CommandBase::intakearms = NULL;
IntakeRollers* CommandBase::intakerollers = NULL;
Lift* CommandBase::lift = NULL;
SlideDrive* CommandBase::slidedrive = NULL;
CommandBase::CommandBase(char const *name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	examplesubsystem = new ExampleSubsystem();

	oi = new OI();
	grabber = new Grabber();
	intakearms = new IntakeArms();
	intakerollers = new IntakeRollers();
	lift = new Lift();
	slidedrive = new SlideDrive();
}
