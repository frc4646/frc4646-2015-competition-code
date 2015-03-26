#ifndef LiftToLevelCommand_H
#define LiftToLevelCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class LiftToLevelCommand: public CommandBase
{
public:
	LiftToLevelCommand(double level, bool ignoreUser = false);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double liftlevel;
	bool isRaising;
	bool userIgnore;
};

#endif
