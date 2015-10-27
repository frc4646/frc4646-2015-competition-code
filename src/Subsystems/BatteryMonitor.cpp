#include "BatteryMonitor.h"
#include "../RobotMap.h"
#include <Commands/BatteryShutdown.h>
static const int BAT_LOW_TIMEOUT=750;
BatteryMonitor::BatteryMonitor() :
		Subsystem("ExampleSubsystem"),
		batLowCount(0)
{

}

void BatteryMonitor::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new BatteryShutdown());

}

void BatteryMonitor::CheckVoltage()
{
//	double voltage = DriverStation::GetInstance()->GetBatteryVoltage();
//	if (voltage < 9) {
//		batLowCount++;
//	}
//	else {
//		batLowCount = 0;
//	}
//	if (batLowCount>=BAT_LOW_TIMEOUT) {
//		voltage/=0;
//	}
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
