#ifndef TurnForRevolutions_H
#define TurnForRevolutions_H

#include "../CommandBase.h"
#include "WPILib.h"

class TurnForRevolutions: public CommandBase
{
private:
	double rotate;
	double power;

public:
	TurnForRevolutions(double rotations, double power);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
