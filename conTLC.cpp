/*
 * conTLC.cpp
 *
 *  Created on: Sep 28, 2016
 *      Author: oturt
 */

#include "conTLC.h"



void tlc_directSetServo(int channel, int value) {
	// ensure value is kept in bounds
	if (value < SERVO_MIN_WIDTH) {
		value = SERVO_MIN_WIDTH;

	} else if (value > SERVO_MAX_WIDTH) {
		value = SERVO_MAX_WIDTH;
	}

	Tlc.set(channel, (4096 - value));
}

void tlc_directSetAllServo(int value) {
	if (value < SERVO_MIN_WIDTH) {
		value = SERVO_MIN_WIDTH;

	} else if (value > SERVO_MAX_WIDTH) {
		value = SERVO_MAX_WIDTH;
	}

	for (int iter = 0; iter != NUM_TLCS * 16; iter++)
	{
		Tlc.set(iter, (4096 - value));
	}
	Tlc.update();
}

