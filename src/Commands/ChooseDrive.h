#ifndef ChooseDrive_H
#define ChooseDrive_H

#include "../CommandBase.h"
#include "WPILib.h"

class ChooseDrive: public CommandBase
{
public:
	ChooseDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
