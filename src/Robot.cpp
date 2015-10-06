#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/ExampleCommand.h"
#include "CommandBase.h"
#include "Commands/AutoCommand.h"
#include "Commands/AutoGrabToteCommand.h"
#include "Commands/AutoStackTotes.h"
#include "Commands/DriveForDistance.h"
#include "Commands/SlideForDistance.h"
#include "Commands/SquareDrive.h"
#include "Commands/TurnForRevolutions.h"
#include "Commands/GrabThenReverse.h"
#include "Commands/TotesMaGoats.h"
#include "Commands/TurnAndForward.h"
#include "Commands/GrabAndLift.h"
#include "Commands/DemoMode.h"
#include "Commands/RotateClockwiseAngle.h"
#include "Commands/RotateCounterclockwiseAngle.h"
#include "Commands/ThreeToteAuto.h"

class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	LiveWindow *lw;
	SendableChooser *chooser;
	Compressor* comp;

	void RobotInit()
	{
		CommandBase::init();
//		autonomousCommand = new SquareDrive();
		chooser = new SendableChooser();
		chooser->AddObject("Grab And Lift", new GrabAndLift());
		chooser->AddObject("Grab And Reverse", new GrabThenReverse());
		chooser->AddObject("Grab Totes", new ThreeToteAuto());
		chooser->AddDefault("Do Nothing", new DriveForDistance(0, 0));
//		chooser->AddDefault("Demo Mode (DO NOT USE AT COMPETITION)", new DemoMode());
//		chooser->AddDefault("foo", new TurnAndForward());
		chooser->AddObject("Turn 90 degrees clockwise", new RotateClockwiseAngle(90, .25));
		chooser->AddObject("Turn 90 degrees counterclockwise", new RotateCounterclockwiseAngle(90, .25));

		SmartDashboard::PutData("Autonomous mode", chooser);
		lw = LiveWindow::GetInstance();
		comp = new Compressor();
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		comp->Start();
		autonomousCommand = (Command*) chooser->GetSelected();
		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		comp->Start();
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);

