/*
 * StageServo.h
 *
 *  Created on: Sep 21, 2016
 *      Author: oturt
 */

#ifndef STAGESERVO_H_
#define STAGESERVO_H_

#include "ServoMod.h"

class StageServo: public ServoMod {
protected:

	static const int dPre = -20; // sets val of delta pre from norm
	int s1 = 152;  // set default values equadistant from each other
	int s2 = 204;
	int s3 = 256;
	int s4 = 307;
	int s5 = 357;
	int s6 = 410;
	int s7 = 460;

	int p1 = 122;
	int p2 = 174;
	int p3 = 226;
	int p4 = 277;
	int p5 = 328;
	int p6 = 380;
	int p7 = 430;

public:
	StageServo();
	StageServo(int, int);
	StageServo(int, int, int, int, int, int, int, int, int);
	StageServo(int, int,
			int, int, int, int, int, int, int,
			int, int, int, int, int, int, int);
	void setval(int, int, int, int, int, int, int);
	virtual ~StageServo();
	int vVal(int);
	int vPre(int);
};

#endif /* STAGESERVO_H_ */
