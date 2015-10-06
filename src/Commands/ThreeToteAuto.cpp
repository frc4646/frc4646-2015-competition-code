#include "ThreeToteAuto.h"
#include "../RobotMap.h"
#include "GrabAndLift.h"
#include "RotateCounterclockwiseAngle.h"
#include "RotateClockwiseAngle.h"
#include "DriveForDistance.h"
#include "IntakeArmsOpenCommand.h"
#include "SetIntakeRollerPower.h"
#include "IntakeArmsCloseCommand.h"
#include "OpenLower.h"
#include "GrabberOpenCommand.h"
#include "GrabberCloseCommand.h"
#include "LiftToLevelCommand.h"

ThreeToteAuto::ThreeToteAuto()
{
	//TODO: Add power argunment to rotate commands
	AddSequential(new IntakeArmsOpenCommand(), .5);         			//Prepare
	AddSequential(new GrabAndLift());                   			//Grab and lift first tote
//	AddSequential(new RotateCounterclockwiseAngle(30, .50)); 			//Turn away from first can
//	AddSequential(new DriveForDistance(36, -.50));            		//Drive forward until in line with first can
//	AddSequential(new RotateClockwiseAngle(45, .50));        			//Turn and knock over first can
	AddParallel(new SetIntakeRollerPower(1));   					//Turn on intake rollers
	AddSequential(new DriveForDistance(54, -.20));            		//Drive until touching second tote
	AddParallel(new IntakeArmsCloseCommand(), .5);          			//Close intake arms around second tote
	AddSequential(new DriveForDistance(24, -.50));            		//Drive forward until fully intaked second tote
	AddSequential(new SetIntakeRollerPower(0));     				//Turn off intake rollers
	AddSequential(new IntakeArmsOpenCommand());         			//Open intake arms
	AddSequential(new OpenLower());                     			//Grabber arms open and lower
	AddSequential(new GrabAndLift());                   			//Grab and lift second tote along with first tote
//	AddSequential(new RotateCounterclockwiseAngle(45, .50)); 			//Turn to realign for third tote
//	AddSequential(new DriveForDistance(36, -.50));            		//Drive forward until in line with second can
//	AddSequential(new RotateClockwiseAngle(45, .50));        			//Turn and knock over second can
	AddParallel(new SetIntakeRollerPower(1), .5);   					//Turn on intake rollers
	AddSequential(new DriveForDistance(24, -.50));            		//Drive until touching third tote
	AddParallel(new IntakeArmsCloseCommand(), .5);          			//Close intake arms around third tote
	AddSequential(new DriveForDistance(24, -.50));            		//Drive forward until fully intaked third tote
	AddSequential(new SetIntakeRollerPower(0));						 //Turn off intake rollers
	AddSequential(new GrabberOpenCommand());						//Open grabbers
	AddSequential(new LiftToLevelCommand(LIFT_LEVEL_THREE, true));  //Lift to hold on to top tote
	AddSequential(new GrabberCloseCommand());						//Close grabbers around top tote
//	AddSequential(new RotateClockwiseAngle(90, .50));					//Rotate 90 degrees right
//	AddSequential(new DriveForDistance(60, -.50));					//Drive 5 feet to the zone
	AddSequential(new GrabberOpenCommand());						//Open grabbers
	AddParallel(new SetIntakeRollerPower(-.75));						//Reverse intakes
	AddSequential(new DriveForDistance(36, -.50));					//Reverse 3 feet
																	//octothorpe include
}
