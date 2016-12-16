/*
 * com.h
 *
 *  Created on: Nov 6, 2016
 *      Author: oturt
 */

#ifndef COM_H_
#define COM_H_

#include "Arduino.h"
#include "wait.h"

#define INCPIN_GRBL	13 //
#define INCPIN_AUX	12 //

#define RECPIN_GRBL	12 //
#define RECPIN_AUX	11 //

int delaytime = 200;
int delaydelay = 50;

int indtimeon =		500;
int indtimeoff =	300;



void sendorder(int num){
	bool isfinish = false;
	while (!isfinish){
		if (digitalRead(RECPIN_GRBL) == HIGH){
			wait(1000);
			digitalWrite(INCPIN_GRBL, HIGH);
			wait(num * delaytime);
			digitalWrite(INCPIN_GRBL, LOW);
			wait(delaytime);
			isfinish = true;
		}
	}
	isfinish = false;
}

int readorder(){
	int counter = 0;
	bool isfirst = true;
	while (1) {
		if (digitalRead (INCPIN_AUX) == HIGH) {
			digitalWrite(RECPIN_AUX, LOW);
			counter++;
			if (isfirst) {
				wait(delaydelay);
				isfirst = false;
			}
			wait(delaytime);
		} else {
			isfirst = true;
			return counter;
		}
	}

}

void disp(int counter){
	while (counter != 0)
	{
		digitalWrite(13, HIGH);
		wait(indtimeon);
		digitalWrite(13, LOW);
		wait(indtimeoff);
		counter--;
	}
	if (counter == 0){
		digitalWrite(RECPIN_AUX, HIGH);
	}
}




#endif /* COM_H_ */
