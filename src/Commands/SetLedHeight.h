#ifndef SetLedHeight_H
#define SetLedHeight_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetLedHeight: public CommandBase
{
public:
	SetLedHeight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
