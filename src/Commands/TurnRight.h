#ifndef TurnRight_H
#define TurnRight_H

#include "../CommandBase.h"
#include "WPILib.h"

class TurnRight: public CommandBase
{
public:
	TurnRight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
