#ifndef SlideForTime_H
#define SlideForTime_H

#include "../CommandBase.h"
#include "WPILib.h"

class SlideForTime: public CommandBase
{
public:
	SlideForTime(double power, double time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void DriveSlide(double speed);
private:
	double driveSpeed;
};

#endif
