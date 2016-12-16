/*
 * LiftServo.h
 *
 *  Created on: Sep 30, 2016
 *      Author: oturt
 */

#ifndef LIFTSERVO_H_
#define LIFTSERVO_H_

#include "ServoMod.h"

class LiftServo: public ServoMod {
private:
	int safeupval;
public:
	LiftServo();
	virtual ~LiftServo();
	LiftServo(int, int, int);
	int vSafeUp();
};

#endif /* LIFTSERVO_H_ */
