/*
 * wait.h
 *
 *  Created on: Nov 6, 2016
 *      Author: oturt
 */

#ifndef WAIT_H_
#define WAIT_H_

#include "Arduino.h"

unsigned long ptime = 0;
unsigned long crtime = 0;


void wait(int x)
{
  do{crtime = millis();} while (crtime - ptime <= x);
  ptime = crtime;
}



#endif /* WAIT_H_ */
