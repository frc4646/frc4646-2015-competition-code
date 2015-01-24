#ifndef IntakeArmsCloseCommand_H
#define IntakeArmsCloseCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class IntakeArmsCloseCommand: public CommandBase
{
public:
	IntakeArmsCloseCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
