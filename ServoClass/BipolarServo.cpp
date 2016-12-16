/*
 * BipolarServo.cpp
 *
 *  Created on: Sep 21, 2016
 *      Author: oturt
 */

#include "BipolarServo.h"

BipolarServo::BipolarServo() {
	// TODO Auto-generated constructor stub

}

BipolarServo::~BipolarServo() {
	// TODO Auto-generated destructor stub
}

BipolarServo::BipolarServo(int p, int c, int s, int o) : ServoMod(p, s) // set safe mode
{
	closeval = c;
	openval = o;

}
int BipolarServo::vClose()  {return closeval;}
int BipolarServo::vOpen()  {return openval;}
int BipolarServo::vActive() {return closeval;}
int BipolarServo::vInactive() {return openval;}

int BipolarServo::vPulse()
{
	if(safeval - openval >= 0) {return safeval - 10;}
	else {return safeval + 10;}
}
int BipolarServo::vBigPulse()
{
	if(safeval - openval >= 0) {return safeval - 25;}
	else {return safeval + 25;}
}
