#ifndef SlideCommand_H
#define SlideCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class SlideCommand: public CommandBase
{
public:
	SlideCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
