#ifndef SetIntakeRollerPower_H
#define SetIntakeRollerPower_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetIntakeRollerPower: public CommandBase
{
public:
	SetIntakeRollerPower(int power);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	int MotorPower;
};

#endif
