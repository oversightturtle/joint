/*
 * MovSpeed.h
 *
 *  Created on: Sep 27, 2016
 *      Author: oturt
 */

#ifndef MOVSPEED_H_
#define MOVSPEED_H_

class MovSpeed {
private:
	int numst;
	int stdel;
	int findel;
public:
	MovSpeed();
	MovSpeed(int, int, int);
	int vN();
	int vD();
	int vF();
	virtual ~MovSpeed();
};

#endif /* MOVSPEED_H_ */
