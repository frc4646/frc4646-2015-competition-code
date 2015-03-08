#ifndef IntakeUntilClose_H
#define IntakeUntilClose_H

#include "../CommandBase.h"
#include "WPILib.h"

class IntakeUntilClose: public CommandBase
{
public:
	IntakeUntilClose(double finalObjectDistance = 30);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	bool IsClose();
private:
	double m_finalObjectDistance;
};

#endif
