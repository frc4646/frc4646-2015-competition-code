#ifndef LiftRaiseCommand_H
#define LiftRaiseCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class LiftRaiseCommand: public CommandBase
{
public:
	LiftRaiseCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
