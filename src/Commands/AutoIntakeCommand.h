#ifndef AutoIntakeCommand_H
#define AutoIntakeCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoIntakeCommand: public CommandBase
{
public:
	AutoIntakeCommand(double Power);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double power;
};

#endif
