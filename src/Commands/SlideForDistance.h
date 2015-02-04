#ifndef SlideForDistance_H
#define SlideForDistance_H

#include "../CommandBase.h"
#include "WPILib.h"

class SlideForDistance: public CommandBase
{
public:
	SlideForDistance(double dist, double power);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double encoderDist;
	double motorPower;
};

#endif
