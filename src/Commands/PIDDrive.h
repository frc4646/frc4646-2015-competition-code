#ifndef PIDDrive_H
#define PIDDrive_H

#include "../CommandBase.h"
#include "WPILib.h"

class PIDDrive: public CommandBase
{
public:
	PIDDrive(double dist, double power);
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
