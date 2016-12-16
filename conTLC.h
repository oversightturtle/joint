/*
 * conTLC.h
 *
 *  Created on: Sep 21, 2016
 *      Author: oturt
 */

#ifndef CONTLC_H_
#define CONTLC_H_

#define SERVO_MIN_WIDTH 102 // val for 500 ms
#define SERVO_MAX_WIDTH 512

#include <tlc_servos.h>
#include <Tlc5940.h>

#define NUM_TLCS 2



void tlc_directSetServo(int channel, int value);
void tlc_directSetAllServo(int value);
//#define SERVO_MIN_WIDTH 102 // val for 500 ms
//#define SERVO_MAX_WIDTH 512 // val for 2500 ms




#endif /* CONTLC_H_ */
