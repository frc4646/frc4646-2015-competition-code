#ifndef RotateClockwiseAngle_H
#define RotateClockwiseAngle_H

#include "../CommandBase.h"
#include "WPILib.h"

class RotateClockwiseAngle: public CommandBase
{
private:
	double StartingAngle;
	double StartingPower;
	double FinishingAngle;
public:
	RotateClockwiseAngle(double angle, double power);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
