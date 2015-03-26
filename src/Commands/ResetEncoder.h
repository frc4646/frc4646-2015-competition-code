#ifndef ResetEncoder_H
#define ResetEncoder_H

#include "../CommandBase.h"
#include "WPILib.h"

class ResetEncoder: public CommandBase
{
public:
	ResetEncoder();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
