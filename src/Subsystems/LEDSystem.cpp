#include "LEDSystem.h"
#include "../RobotMap.h"
#include "string"
#include "Commands/SetLedHeight.h"

LEDSystem::LEDSystem() :
		Subsystem("LEDSystem"),
		serialPort(9600, SerialPort::kUSB)
{
	serialPort.SetFlowControl(SerialPort::kFlowControl_None);
	serialPort.SetWriteBufferMode(SerialPort::kFlushOnAccess);
	serialPort.SetWriteBufferSize(10);
	serialPort.Reset();
}

void LEDSystem::InitDefaultCommand()
{
	SetDefaultCommand(new SetLedHeight());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void LEDSystem::sendLEDHeight(int centerLEDHeight) {
	std::string strHeight = std::to_string(centerLEDHeight) + "\n";
	serialPort.Write(strHeight.c_str(), (int)strHeight.length());
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
