/*
 * decMovSpeed.h
 *
 *  Created on: Sep 27, 2016
 *      Author: oturt
 */

#ifndef DECMOVSPEED_H_
#define DECMOVSPEED_H_

#include "MovSpeed.h"

MovSpeed FASTSMOOTH(45, 120, 2000);

MovSpeed NORMAL(15, 250, 700);

MovSpeed SLOW(10, 350, 1000);

MovSpeed SLOWPULSE(15, 300, 100);

MovSpeed FASTPULSE(6, 300, 100);

MovSpeed FAST(10, 100, 2500);

MovSpeed NDFAST(10, 100, 0);

MovSpeed SAFEM(5, 100, 500);

MovSpeed INSTANT(1, 100, 1000);



#endif /* DECMOVSPEED_H_ */
