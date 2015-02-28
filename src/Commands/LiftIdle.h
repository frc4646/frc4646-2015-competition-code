#ifndef LiftIdle_H
#define LiftIdle_H

#include "../CommandBase.h"
#include "WPILib.h"

class LiftIdle: public CommandBase
{
public:
	LiftIdle();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
