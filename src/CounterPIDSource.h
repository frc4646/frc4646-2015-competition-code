/*
 * CounterPIDSource.h
 *
 *  Created on: Jan 31, 2015
 *      Author: User
 */

#ifndef SRC_COUNTERPIDSOURCE_H_
#define SRC_COUNTERPIDSOURCE_H_

#include "WPILib.h"

class CounterPIDSource: public PIDSource {
public:
	CounterPIDSource(Counter& counter, double scaleFactor);
	virtual ~CounterPIDSource();
	virtual double PIDGet();
private:
	Counter & source;
	double scale;
};

#endif /* SRC_COUNTERPIDSOURCE_H_ */
