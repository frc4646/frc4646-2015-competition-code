#ifndef LEDSystem_H
#define LEDSystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <SerialPort.h>

class LEDSystem: public Subsystem
{
private:
	SerialPort serialPort;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	LEDSystem();
	void InitDefaultCommand();
	void sendLEDHeight(int centerLEDHeight);
};

#endif
