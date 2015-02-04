#ifndef HolonomicDrive_H
#define HolonomicDrive_H

#include "../CommandBase.h"
#include "WPILib.h"

class HolonomicDrive: public CommandBase
{
public:
	HolonomicDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
