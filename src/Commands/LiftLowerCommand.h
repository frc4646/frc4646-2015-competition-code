#ifndef LiftLowerCommand_H
#define LiftLowerCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class LiftLowerCommand: public CommandBase
{
public:
	LiftLowerCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
