#ifndef RotateCounterclockwiseAngle_H
#define RotateCounterclockwiseAngle_H

#include "../CommandBase.h"
#include "WPILib.h"

class RotateCounterclockwiseAngle: public CommandBase
{
private:
	double StartingAngle;
	double StartingPower;
	double FinishingAngle;
public:
	RotateCounterclockwiseAngle(double power, double angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
