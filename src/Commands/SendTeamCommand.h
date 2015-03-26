#ifndef SendTeamCommand_H
#define SendTeamCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class SendTeamCommand: public CommandBase
{
public:
	SendTeamCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
