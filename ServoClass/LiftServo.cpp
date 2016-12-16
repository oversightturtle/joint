/*
 * LiftServo.cpp
 *
 *  Created on: Sep 30, 2016
 *      Author: oturt
 */

#include "LiftServo.h"

LiftServo::LiftServo() {
	// TODO Auto-generated constructor stub

}

LiftServo::~LiftServo() {
	// TODO Auto-generated destructor stub
}

LiftServo::LiftServo(int p, int s , int up): ServoMod(p, s){
	safeupval = up;
}

int LiftServo::vSafeUp(){
	return safeupval;
}
