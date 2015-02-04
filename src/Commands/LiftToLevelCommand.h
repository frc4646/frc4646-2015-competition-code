#ifndef LiftToLevelCommand_H
#define LiftToLevelCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class LiftToLevelCommand: public CommandBase
{
public:
	LiftToLevelCommand(double level);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double liftlevel;
};

#endif
