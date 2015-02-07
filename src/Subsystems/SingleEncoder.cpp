/*
 * SingleEncoder.cpp
 *
 *  Created on: Feb 6, 2015
 *      Author: User
 */

#include <Subsystems/SingleEncoder.h>

SingleEncoder::SingleEncoder(int32_t channel):
Counter(channel),
DistancePerPulse(1.0),
PidSource(PIDSource::kDistance)
{
	// TODO Auto-generated constructor stub

}

SingleEncoder::~SingleEncoder() {
	// TODO Auto-generated destructor stub
}

double SingleEncoder::GetDistance() {
	return Get()*DistancePerPulse;
}

double SingleEncoder::GetRate() {
	return GetPeriod()*GetDistance();
}

void SingleEncoder::SetDistancePerPulse(double distancePerPulse) {
	DistancePerPulse = distancePerPulse;

}

void SingleEncoder::SetPIDSourceParameter(PIDSourceParameter pidSource) {
	PidSource = pidSource;
}

double SingleEncoder::PIDGet() {
	if(PidSource == PIDSource::kRate)
	{
		return GetRate();
	}
	else
	{
		return GetDistance();
	}
}
