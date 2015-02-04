#ifndef DriveForDistance_H
#define DriveForDistance_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveForDistance: public CommandBase
{
public:
	DriveForDistance(double dist, double power);
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
