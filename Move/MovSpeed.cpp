/*
 * MovSpeed.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: oturt
 */

#include "MovSpeed.h"

MovSpeed::MovSpeed() {
	// TODO Auto-generated constructor stub

}

MovSpeed::~MovSpeed() {
	// TODO Auto-generated destructor stub
}

MovSpeed::MovSpeed( int n, int d, int f){
	numst = n;
	stdel = d;
	findel = f;
}

int MovSpeed::vN() { return numst; }
int MovSpeed::vD() { return stdel; }
int MovSpeed::vF() { return findel;}
