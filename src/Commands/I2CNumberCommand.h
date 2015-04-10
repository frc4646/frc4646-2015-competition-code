#ifndef I2CNumberCommand_H
#define I2CNumberCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class I2CNumberCommand: public CommandBase
{
public:
	I2CNumberCommand(int NumberToSend);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	int numberToSend;
};

#endif
