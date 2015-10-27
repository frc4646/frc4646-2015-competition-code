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
	DoubleSolenoid CanGrabber;
public:
	Grabber();
	void InitDefaultCommand();
	void Open();
	void Close();
	void CanOpen();
	void CanClose();
	void Idle();
	void CanIdle(); //These look like booleans but deal with it
};

#endif
