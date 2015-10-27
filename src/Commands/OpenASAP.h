#ifndef OpenASAP_H
#define OpenASAP_H

#include "../CommandBase.h"
#include "WPILib.h"

class OpenASAP: public CommandBase
{
public:
	OpenASAP();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
