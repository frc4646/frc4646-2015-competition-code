#ifndef LiftToTopCommand_H
#define LiftToTopCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class LiftToTopCommand: public CommandBase
{
public:
	LiftToTopCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
