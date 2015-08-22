#ifndef GetGyro_H
#define GetGyro_H

#include "../CommandBase.h"
#include "WPILib.h"

class GetGyro: public CommandBase
{
public:
	GetGyro();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
