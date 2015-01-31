#ifndef AutoCommand_H
#define AutoCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoCommand: public CommandGroup
{
public:
	AutoCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
