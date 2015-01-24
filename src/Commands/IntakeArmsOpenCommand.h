#ifndef IntakeArmsOpenCommand_H
#define IntakeArmsOpenCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class IntakeArmsOpenCommand: public CommandBase
{
public:
	IntakeArmsOpenCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
