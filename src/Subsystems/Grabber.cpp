#include "Grabber.h"
#include "../RobotMap.h"

Grabber::Grabber() :
		Subsystem("Grabber"),
		GrabberSolenoid(GRABBER_OPEN_PORT, GRABBER_CLOSE_PORT)
{

}

void Grabber::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Grabber::Open() {
	GrabberSolenoid.Set(DoubleSolenoid::kForward);
}

void Grabber::Close() {
	GrabberSolenoid.Set(DoubleSolenoid::kReverse);
}

void Grabber::Idle() {
	GrabberSolenoid.Set(DoubleSolenoid::kOff);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
