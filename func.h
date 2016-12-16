/*
 * func.h
 *
 *  Created on: Sep 21, 2016
 *      Author: oturt
 */

#ifndef FUNC_H_
#define FUNC_H_

void vac_off()
{
#ifdef ENABLE_VAC
	digitalWrite(pin_s0_vac, LOW);
	wait(500);
#endif
}

void vac_on()
{
//	digitalWrite(pin_s0_vac, HIGH);
	wait(500);
}

void s0_expand()
{
	//sMove(FAST, s0_lift1, 106, s0_lift2, 70, s0_pitch, 90, s0_yaw, 90,s0_roll, 90);
	wait(500);
}

void s0_retract()
{
	//sMove(FAST, s0_lift1, s0_lift1.vSafe(), s0_lift2,  s0_lift2.vSafe() , s0_pitch,  s0_pitch.vSafe() , s0_yaw,  s0_yaw.vSafe() ,s0_roll,  s0_roll.vSafe());
	wait(500);
}

#endif /* FUNC_H_ */
