/*
 * ServoMod.cpp
 *
 *  Created on: Sep 21, 2016
 *      Author: oturt
 */

#include "ServoMod.h"

#include "../conTLC.h"
extern double * pPos[NUM_TLCS * 16];

ServoMod::ServoMod() {
	// TODO Auto-generated constructor stub

}

ServoMod::~ServoMod() {
	// TODO Auto-generated destructor stub
}

void ServoMod::config(){

	// sets current location to safemode (at beggning (w/ assumption))
	*(pPos[pinval]) = safeval;


}
ServoMod::ServoMod(int p, int s) {
	pinval = p;
	safeval = s;


}

void ServoMod::setpos(int x){
	*(pPos[pinval]) = x;
}

int ServoMod::vPin() {
	return pinval;
}

int ServoMod::vSafe() {
	return safeval;
}

int ServoMod::vClose() {
	return safeval;
}

int ServoMod::vOpen() {
	return safeval;
}

int ServoMod::vActive() {
	return safeval;
}

int ServoMod::vInactive() {
	return safeval;
}

int ServoMod::vPos() {
	return *(pPos[pinval]);
}

void ServoMod::writepos(double x) {
	tlc_setServo(pinval, x);
	Tlc.update();
	*(pPos[pinval]) = x;
}

int ServoMod::vPulse(){return safeval + 10;}
int ServoMod::vBigPulse(){
	if (safeval <= (502 - 40)){
		return safeval + 40;
	} else {
		return safeval - 40;
	}
}

