/*
 * led.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: oturt
 */

#include "led.h"




led::led() {
	// TODO Auto-generated constructor stub

}

led::led(int pin){
	pinval = pin;
	pinMode(pinval, OUTPUT);
}

led::led(int pin, bool st = 1){
	pinval = pin;
	state = st;
	LEDpins.push_back(pin);
	digitalWrite(pinval, state);
}

void led::turn_on(){
	state = 1;
	digitalWrite(pinval, state);
}

void led::turn_off(){
	state = 0;
	digitalWrite(pinval, state);
}

void led::invert(){
	if (state == 1) { turn_off(); } else { turn_on(); }
}

led::~led() {
	// TODO Auto-generated destructor stub
}

