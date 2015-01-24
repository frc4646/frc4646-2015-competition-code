#ifndef Grabber_H
#define Grabber_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Grabber: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	DoubleSolenoid GrabberSolenoid;
public:
	Grabber();
	void InitDefaultCommand();
	void Open();
	void Close();
	void Idle();
};

#endif
