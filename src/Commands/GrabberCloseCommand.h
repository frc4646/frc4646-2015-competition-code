#ifndef GrabberCloseCommand_H
#define GrabberCloseCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class GrabberCloseCommand: public CommandBase
{
public:
	GrabberCloseCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
