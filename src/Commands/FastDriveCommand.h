#ifndef FastDriveCommand_H
#define FastDriveCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class FastDriveCommand: public CommandBase
{
public:
	FastDriveCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
