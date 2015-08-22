#ifndef BatteryShutdown_H
#define BatteryShutdown_H

#include "../CommandBase.h"
#include "WPILib.h"

class BatteryShutdown: public CommandBase
{
public:
	BatteryShutdown();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
