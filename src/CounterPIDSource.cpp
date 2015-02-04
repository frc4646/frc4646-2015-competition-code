/*
 * CounterPIDSource.cpp
 *
 *  Created on: Jan 31, 2015
 *      Author: User
 */

#include <CounterPIDSource.h>

CounterPIDSource::CounterPIDSource(Counter& counter, double scaleFactor):
source(counter),
scale(scaleFactor)
{
	// TODO Auto-generated constructor stub

}

CounterPIDSource::~CounterPIDSource() {
	// TODO Auto-generated destructor stub
}

double CounterPIDSource::PIDGet() {
	return scale/source.GetPeriod();
}
