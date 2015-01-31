#ifndef StraightDriveCommand_H
#define StraightDriveCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class StraightDriveCommand: public CommandBase
{
public:
	StraightDriveCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
