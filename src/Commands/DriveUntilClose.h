#ifndef DriveUntilClose_H
#define DriveUntilClose_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveUntilClose: public CommandBase
{
public:
	DriveUntilClose(double finalObjectDistance = 30);
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
