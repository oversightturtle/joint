/*
 * ServoMod.h
 *
 *  Created on: Sep 21, 2016
 *      Author: oturt
 */

#ifndef SERVOMOD_H_
#define SERVOMOD_H_

//#include "../conTLC.h"
//#include "../pospoint.h"

class ServoMod {
//	friend class robot;
private:

protected:
	int pinval;
	double safeval;

public:
	ServoMod();
	virtual ~ServoMod();
	ServoMod(int, int);
	int vPin();
	int vSafe();
	int vPos();
	void setpos(int);
	virtual int vClose();
	virtual int vOpen();
	virtual int vActive();
	virtual int vInactive();
	void writepos(double x);
	void config();
	virtual int vPulse();
	virtual int vBigPulse();
};

#endif /* SERVOMOD_H_ */
