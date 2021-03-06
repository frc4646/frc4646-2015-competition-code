#ifndef TankAndSlideCommand_H
#define TankAndSlideCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class TankAndSlideCommand: public CommandBase
{
public:
	TankAndSlideCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
