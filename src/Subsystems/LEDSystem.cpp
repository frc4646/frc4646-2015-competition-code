#include "LEDSystem.h"
#include "../RobotMap.h"
#include "string"
#include "Commands/SetLedHeight.h"
#include <stdio.h>      // standard input / output functions
#include <stdlib.h>
#include <string.h>     // string function definitions
#include <unistd.h>     // UNIX standard function definitions
#include <fcntl.h>      // File control definitions
#include <errno.h>      // Error number definitions
#include <termios.h>

LEDSystem::LEDSystem() :
		Subsystem("LEDSystem")
{
	USB = open( "/dev/ttyACM1", O_RDWR| O_NOCTTY );
	if (USB == -1)
	{
		USB = open( "/dev/ttyACM0", O_RDWR| O_NOCTTY );
	}
	struct termios tty;
	struct termios tty_old;
	memset (&tty, 0, sizeof tty);

	/* Error Handling */
	if ( tcgetattr ( USB, &tty ) != 0 ) {
	   std::cout << "Error " << errno << " from tcgetattr: " << strerror(errno) << std::endl;
	}

	/* Save old tty parameters */
	tty_old = tty;

	/* Set Baud Rate */
	cfsetospeed (&tty, (speed_t)B115200);
	cfsetispeed (&tty, (speed_t)B115200);

	/* Setting other Port Stuff */
	tty.c_cflag     &=  ~PARENB;            // Make 8n1
	tty.c_cflag     &=  ~CSTOPB;
	tty.c_cflag     &=  ~CSIZE;
	tty.c_cflag     |=  CS8;

	tty.c_cflag     &=  ~CRTSCTS;           // no flow control
	tty.c_cc[VMIN]   =  1;                  // read doesn't block
	tty.c_cc[VTIME]  =  5;                  // 0.5 seconds read timeout
	tty.c_cflag     |=  CREAD | CLOCAL;     // turn on READ & ignore ctrl lines

	/* Make raw */
	cfmakeraw(&tty);

	/* Flush Port, then applies attributes */
	tcflush( USB, TCIFLUSH );
	if ( tcsetattr ( USB, TCSANOW, &tty ) != 0) {
	   std::cout << "Error " << errno << " from tcsetattr" << std::endl;
	}
}


void LEDSystem::InitDefaultCommand()
{
//	SetDefaultCommand(new SetLedHeight());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void LEDSystem::sendLEDHeight(int centerLEDHeight) {
	std::string strHeight = std::to_string(centerLEDHeight) + "\n";
	write(USB, strHeight.c_str(), strHeight.length());
	fsync(USB);

//	serialPort.Write(strHeight.c_str(), (int)strHeight.length());
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
