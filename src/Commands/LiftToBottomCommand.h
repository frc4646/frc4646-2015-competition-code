#ifndef LiftToBottomCommand_H
#define LiftToBottomCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class LiftToBottomCommand: public CommandBase
{
public:
	LiftToBottomCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
