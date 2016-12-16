/*
 * BipolarServo.h
 *
 *  Created on: Sep 21, 2016
 *      Author: oturt
 */

#ifndef BIPOLARSERVO_H_
#define BIPOLARSERVO_H_

#include "ServoMod.h"

class BipolarServo: public ServoMod {
protected:
	double openval;
	double closeval;

public:
	BipolarServo();
	virtual ~BipolarServo();
	BipolarServo(int, int, int, int);

	int vClose();
	int vOpen();
	int vActive();
	int vInactive();

	int vPulse();
	int vBigPulse();

};

#endif /* BIPOLARSERVO_H_ */
