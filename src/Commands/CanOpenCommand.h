#ifndef CanOpenCommand_H
#define CanOpenCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class CanOpenCommand: public CommandBase
{
public:
	CanOpenCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
