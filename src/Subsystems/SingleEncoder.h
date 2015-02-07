/*
 * SingleEncoder.h
 *
 *  Created on: Feb 6, 2015
 *      Author: User
 */

#ifndef SRC_SUBSYSTEMS_SINGLEENCODER_H_
#define SRC_SUBSYSTEMS_SINGLEENCODER_H_

#include "WPILib.h"

class SingleEncoder : public Counter, PIDSource{
public:
	SingleEncoder(int32_t);
	virtual ~SingleEncoder();

	double GetDistance();
	double GetRate();
	void SetDistancePerPulse(double distancePerPulse);
	void SetPIDSourceParameter(PIDSourceParameter pidSource);
	double PIDGet();
private:
	double DistancePerPulse;
	PIDSource::PIDSourceParameter PidSource;

};

#endif /* SRC_SUBSYSTEMS_SINGLEENCODER_H_ */
