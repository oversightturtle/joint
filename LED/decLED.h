/*
 * decLED.h
 *
 *  Created on: Sep 27, 2016
 *      Author: oturt
 */

#ifndef DECLED_H_
#define DECLED_H_

#include "led.h"
#include "Vector.h"
#include "Arduino.h"

/*
#define pin_safelight1 33 // >> this is operation light
#define pin_safelight2 31 // >> gthis is safe light
#define pin_debuglight1 35
#define pin_debuglight2 37
*/

Vector<int> LEDpins;

void conLED(){
	for( int iii = 0; iii != LEDpins.size(); iii++)
	{
		pinMode(LEDpins[iii], OUTPUT);
	}
}


led safelight(33, 1);
led operlight(31, 1);
led debug1(35, 1);
led debug2(37, 1);





#endif /* DECLED_H_ */
