#ifndef LiftForTime_H
#define LiftForTime_H

#include "../CommandBase.h"
#include "WPILib.h"

class LiftForTime: public CommandBase
{
public:
	LiftForTime(double Speed, double time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double speed;
};

#endif
