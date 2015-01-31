#ifndef SlideOnlyCommand_H
#define SlideOnlyCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class SlideOnlyCommand: public CommandBase
{
public:
	SlideOnlyCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
