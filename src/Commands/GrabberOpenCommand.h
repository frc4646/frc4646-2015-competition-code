#ifndef GrabberOpenCommand_H
#define GrabberOpenCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class GrabberOpenCommand: public CommandBase
{
public:
	GrabberOpenCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
