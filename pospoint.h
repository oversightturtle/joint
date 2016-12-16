/*
 * pospoint.h
 *
 *  Created on: Sep 21, 2016
 *      Author: oturt
 */

#ifndef POSPOINT_H_
#define POSPOINT_H_


#include "conTLC.h"
//#include "conTLC.h" // for num tlc
//#include "ServoClass/ServoMod.h"

// are attached to the pins. >> DO NOT CHANGE PINS ON A SERVO CLASS

// declares (ini) current_position pin


double pos[NUM_TLCS * 16];
double * pPos[NUM_TLCS * 16];


ServoMod * pServo[NUM_TLCS * 16];

ServoMod * pOrder[NUM_TLCS * 16];

bool pExist[NUM_TLCS * 16]; // returns tue if the pin has been initialized

// declares (ini) safe_values pins
//double safe[NUM_TLCS * 16];
//double * pSafe[NUM_TLCS * 16];



// init pospoint must go in setup
void init_pospoint() // sync the pins to pointers
{
    for (int i = 0; i != NUM_TLCS * 16; i++)
  {
     pPos[i] = &pos[i]; // sync and declares position pins
//     pSafe[i] = &safe[i];
     pExist[i] = 0;
  }
}
/*
void init_pin(ServoMod x)
{
	// sets current location to safemode (at beggning (w/ assumption))
	*(pPos[x.vPin()]) = x.vSafe();
	// sets safeval to pointer of safeval (used for ending)
	*(pSafe[x.vPin()]) = x.vSafe();

}

// link config command in servomod autoconfig all;
 // map alg???????????????????????????????????????????????????????????????????????????????????

void init_posPointSafe()
{
//	*(pPos[pin_s0_base]) = s0_base.vSafe();
//	init_pin(s0_base);
;
}
*/
#endif /* POSPOINT_H_ */
