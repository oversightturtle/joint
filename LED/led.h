/*
 * led.h
 *
 *  Created on: Sep 27, 2016
 *      Author: oturt
 */

#ifndef LED_H_
#define LED_H_

#include "Arduino.h"
#include "Vector.h"

extern Vector<int> LEDpins;


class led {
private:
	int pinval;
	bool state;

public:
	led();
	led(int);
	led(int, bool);
	virtual ~led();
	void turn_on();
	void turn_off();
	void invert();
};

#endif /* LED_H_ */
