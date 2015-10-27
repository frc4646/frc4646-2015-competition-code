#ifndef CanCloseCommand_H
#define CanCloseCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class CanCloseCommand: public CommandBase
{
public:
	CanCloseCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
